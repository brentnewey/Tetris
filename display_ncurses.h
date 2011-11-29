#ifndef INC_DISPLAY_H
#define INC_DISPLAY_H

#include <curses.h>

#include "pipe.h"

/* The screen edge for drawing purposes */
#define SCREEN_LEFT_EDGE 0
#define SCREEN_TOP_EDGE 0

#define PIPE_EDGE_HEIGHT 1
#define PIPE_EDGE_WIDTH 1

/* The space between the pipe and the preview pane */
#define SEPARATION_BUFFER 2

#define TETRAD_TILE_TEXTURE ' '
#define PIPE_VERTICAL_BOUNDARY_TEXTURE '|'
#define PIPE_HORIZONTAL_BOUNDARY_TEXTURE '-'
#define PIPE_CORNER_TEXTURE '+'
#define EMPTY_TILE_TEXTURE ' '

void DrawBox(int left_x, int right_x, int upper_y, int lower_y),
  DrawPlayingArea(),
  UpdateDisplay(),
  InitializeDisplay(int left_edge);

#endif
