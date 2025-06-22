#include "control_sdl.h"
#include "display_sdl.h"

#define BASE_SPEED 1000

int pause, wait, top;
Uint32 start_interval, end_interval, start_wait, end_wait, paused_time;
SDL_Event event;

int GameOver() {
  return 0;
}

void SetClock() {

  end_interval =
    (start_interval = SDL_GetTicks()) + 
    (
     level < 10 ? 
     BASE_SPEED * (1.0 - level * 7.0 / 80.0) : 
     BASE_SPEED * (1.0 / 8.0) - 
     BASE_SPEED * (1.0 / 8.0) * ((level - 10.0) / 10.0)
     );
  if(top) {
    end_interval = MAX(start_interval + BASE_SPEED / 2, end_interval);
    top = 0;
  }

}


int ControlLoop() {

  struct timespec sleep_time = {0, 1};

  lines_cleared =  INITIAL_LINES_CLEARED;
  score = INITIAL_SCORE;
  level = (level != -1 ? level : INITIAL_LEVEL);

  UpdateDisplay();
  wait = 0;
  top = 1;

  while (1) {
    SetClock();

    while(start_interval < end_interval) {


      Uint8 *keystates = SDL_GetKeyState(NULL);
      if(SDL_PollEvent(&event)) {
	if(SDL_KEYDOWN == event.type) {
	  wait = 1;
	  start_wait = SDL_GetTicks();
	  end_wait = start_wait + 0.25 * BASE_SPEED;
	  if(!pause) {
	    switch(event.key.keysym.sym) {
	    case SDLK_LEFT:   if(!AgainstLeftWall()) ShiftTetradLeft();
	      UpdateDisplay();
	      break;
	      
	    case SDLK_RIGHT:	if(!AgainstRightWall()) ShiftTetradRight();
	      UpdateDisplay();
	      break;
	      
	    case SDLK_z:
	      RotateClockwise();
	      UpdateDisplay();
	      break;
	      
	    case SDLK_x:
	      Flip();
	      UpdateDisplay();
	      break;
	      

	    case SDLK_UP:
	    case SDLK_c:
	      RotateCounterClockwise();
	      UpdateDisplay();
	      break;
	      
	    case SDLK_DOWN:
	      if(!MadeContact()) {
		ShiftTetradDown();
		UpdateDisplay();
		SetClock();
	      }
	      else if(!EndPlay()) return 0;
	      break;
	    
	    case SDLK_SPACE:
	      for(;!MadeContact(); score += level + 1) ShiftTetradDown();
	      UpdateDisplay();
	      if(!EndPlay()) return 0;;
	      break;
	    default: break;
	    }
	  }
	  
	  if(SDLK_p == event.key.keysym.sym) {
	    if((pause = !pause)) {
	      paused_time = end_interval - start_interval;
	      PauseDisplay();
	    }
	    else end_interval = (start_interval = SDL_GetTicks()) + paused_time;
	  }
          if(SDLK_q == event.key.keysym.sym) return 0;
	}
	else if(SDL_QUIT == event.type) return 0;
      }
      if(keystates[SDLK_DOWN]) {
	if(start_wait >= end_wait) {
	  if(!MadeContact()) {
	    ShiftTetradDown();
	    UpdateDisplay();
	    SetClock();
	    start_wait = SDL_GetTicks();
	    end_wait = start_wait + 0.05 * BASE_SPEED;
	  }
	  else {
	    EndPlay();
	    start_wait = SDL_GetTicks();
	    end_wait = start_wait + 0.25 * BASE_SPEED;
	  }
	}
	else start_wait = SDL_GetTicks();
      }
      if(keystates[SDLK_LEFT]) {
	if(start_wait >= end_wait) {
	  if(!AgainstLeftWall()) ShiftTetradLeft();
	UpdateDisplay();
	  start_wait = SDL_GetTicks();
	  end_wait = start_wait + 0.05 * BASE_SPEED;
	}
	else start_wait = SDL_GetTicks();
      }
      if(keystates[SDLK_RIGHT]) {
	if(start_wait >= end_wait) {
	  if(!AgainstRightWall()) ShiftTetradRight();
	UpdateDisplay();
	  start_wait = SDL_GetTicks();
	  end_wait = start_wait + 0.05 * BASE_SPEED;
	}
	else start_wait = SDL_GetTicks();
      }
      else wait = 0;
      if(!pause) {
	start_interval = top ? end_interval : SDL_GetTicks();
      }
      nanosleep(&sleep_time, NULL);
    }
    
    if(MadeContact() && !EndPlay()) return 0;
    else if(!top) {
      ShiftTetradDown();
      	UpdateDisplay();
    }

    
  }
  
}

int EndPlay() {
	int lines;
	SolidifyTetrad();
	UpdateDisplay();
	NukeLines();
	lines = ClearLines();
	score += lines * lines * (level + 1) * 100;
	lines_cleared += lines;
	if (lines_cleared / 10 > level) level++;
  if (!GenerateTetrad()) return GameOver();
	top = 1;
	UpdateDisplay();

  return 1;
}
