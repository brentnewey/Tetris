#include <stdlib.h>
#include <time.h>

#include "tetris_sdl.h"
#include "display_sdl.h"
#include "generate.h"
#include "pipe.h"
#include "control_sdl.h"

void Initialize(char* font) {
  
  current_tetrad = tetrad_null;
  next_tetrad = tetrad_null;

  pipe_last_x = PIPE_W - 1;
  pipe_last_y = PIPE_H - 1;

  InitializeTetrads();

  InitializeDisplay(font);
  srand((unsigned int)time(NULL));
  GenerateTetrad();
  UpdateDisplay();
}

int main(int argc, char **argv) {
  int i;
  char* font_string = "";

  level = -1;

  for(i = 0; i < argc; i++) {
    if(argv[i][0] == '-' && i + 1 < argc) {
      switch(argv[i][1]) {
        case 'l': level = atoi(argv[i+1]);
                  break;
        case 'f': font_string = argv[i+1];
                  break;
      }
    }
  } 

  Initialize(font_string);
  ControlLoop();
  TerminateDisplay();
  return 0;
}

