#include "control_ncurses.h"
#include "display_ncurses.h"

bool doloop, pause;
clock_t start_interval, end_interval;
int current_getch;

void GameOver() {
  endwin();
  printf("GAME OVER\n");
  exit(0);
}

void SetClock(void) {
  start_interval = clock();
  if(level < 10) {
    // Make level 0 much faster, and scale up to the same speed at level 10 as before
    double slowest = 0.5; // Level 0: half the original wait
    double fastest = 1.0 - 9 * 7.0 / 80.0; // Level 9: same as before
    double base = slowest + (fastest - slowest) * (level / 9.0);
    end_interval = start_interval + CLOCKS_PER_SEC * base;
  } else {
    end_interval = start_interval + CLOCKS_PER_SEC * (1.0 / 8.0) -
      CLOCKS_PER_SEC * (1.0 / 8.0) * ((level - 10.0) / 10.0);
  }
}

int control_loop() {

  int score_tally, score_tally2;

  struct timespec sleep_time = {0, 1};

  keypad(stdscr,true);
  while (doloop) {
    SetClock();
    while(start_interval<end_interval) {
      current_getch = getch();
      if ('q'==current_getch) doloop = 0;
      if (KEY_LEFT==current_getch && !pause) {
	if(!AgainstLeftWall()) ShiftTetradLeft();
	UpdateDisplay();
      }
      else if (KEY_RIGHT==current_getch && !pause) {
	if(!AgainstRightWall()) ShiftTetradRight();
	UpdateDisplay();
      }
      else if ('z'==current_getch && !pause){
	RotateClockwise();
	UpdateDisplay();
      }
      else if('x'==current_getch && !pause){
	Flip();
	UpdateDisplay();
      }
      else if ('c'==current_getch && !pause){
	RotateCounterClockwise();
	UpdateDisplay();
      }
      else if(KEY_UP==current_getch && !pause){
	RotateClockwise();
	UpdateDisplay();
      }
      else if(KEY_DOWN==current_getch && !pause){
	if(!MadeContact()) {
	  ShiftTetradDown();
	  SetClock();
	  UpdateDisplay();
	}
      }
      else if(' '==current_getch && !pause){
	int score_tally = 0;
	while(!MadeContact()){
	  score_tally += 1;
	  ShiftTetradDown();
	}
	score += score_tally * (level+1);
	SolidifyTetrad();
	score_tally2 = ClearLines();
	score += score_tally2 * score_tally2 * (level+1) * 100;
	lines_cleared += score_tally2;
	if (lines_cleared/10 > level) level++;
	if (!GenerateTetrad()) GameOver();
	UpdateDisplay();
      }
      else if('p'==current_getch){
	pause = !pause;
      }
      if(!pause) start_interval=clock();
      nanosleep(&sleep_time, NULL);
    }
    if (current_getch == 'q') {
        doloop = 0;
    }
    if(MadeContact()) {
      SolidifyTetrad();
      score_tally = ClearLines();
      score += score_tally * score_tally * (level+1) * 100;
      lines_cleared += score_tally;
      if (lines_cleared/10 > level) level++;
      if (!GenerateTetrad()) GameOver();
    }
    else {
      ShiftTetradDown();
    }
    UpdateDisplay();
  }
  endwin();
  printf("Bye!\n");
  return 0;
}
