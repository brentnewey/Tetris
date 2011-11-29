#include <stdlib.h>
#include <time.h>
#include <curses.h>

#include "tetris_ncurses.h"
#include "display_ncurses.h"
#include "generate.h"
#include "pipe.h"
#include "control_ncurses.h"

void Initialize(int initial_level) {
  pause = false;
  doloop = true;
  
  current_tetrad = tetrad_null;
  next_tetrad = tetrad_null;
  lines_cleared =  INITIAL_LINES_CLEARED;
  score = INITIAL_SCORE;
  level = initial_level;
  pipe_last_x = PIPE_W - 1;
  pipe_last_y = PIPE_H - 1;

  InitializeDisplay(
		    SCREEN_LEFT_EDGE + 2 * PIPE_EDGE_WIDTH + 
		    PIPE_W + SEPARATION_BUFFER
		    );

  InitializeTetrads();

  DrawPlayingArea();
  srand(time(NULL));
  GenerateTetrad();
  UpdateDisplay();
}

int main(int argc, char **argv) {
  int level = INITIAL_LEVEL;
  for(int i = 0; i < argc; i++) {
    if(argv[i][0] == '-' && argv[i][1] == 'l') level = atoi(argv[i+1]);
  } 
  Initialize(level);
  control_loop();
}
