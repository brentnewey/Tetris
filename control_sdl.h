#ifndef INC_CONTROL_H
#define INC_CONTROL_H

#include <time.h>
#include <stdlib.h>

#include "SDL/SDL.h"
#include "pipe.h"

#define MAX(a,b) ((a) < (b) ? (b) : (a))

#define INITIAL_SCORE 0
#define INITIAL_LINES_CLEARED 0
#define INITIAL_LEVEL 0

int pause, wait, top;
Uint32 start_interval, end_interval, start_wait, end_wait, paused_time;
SDL_Event event;

int GameOver(), ControlLoop(), EndPlay();

void SetClock(void);

#endif
