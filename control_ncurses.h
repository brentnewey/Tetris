#ifndef INC_CONTROL_H
#define INC_CONTROL_H

#include <time.h>
#include <stdlib.h>
#include <curses.h>

#include "pipe.h"

extern bool doloop, pause;

extern clock_t start_interval, end_interval;
extern int current_getch;

void GameOver();
void SetClock(void);
int control_loop();

#endif
