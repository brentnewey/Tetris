#ifndef INC_DISPLAY_H
#define INC_DISPLAY_H

#include <time.h>

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

#include "pipe.h"

#define MAX(a,b) ((a) < (b) ? (b) : (a))

/* The screen edge for drawing purposes */
#define SCREEN_LEFT_EDGE 0
#define SCREEN_TOP_EDGE 0

#define PIPE_EDGE_H 1
#define PIPE_EDGE_W 1

#define BLOCK_BORDER_H 1
#define BLOCK_BORDER_W 1

#define BLOCK_W 20
#define BLOCK_H 20

/* The space on either side of the preview pane */
#define H_SEP_BUFFER 40
#define V_SEP_BUFFER 20

#define P_WDT   (BLOCK_W * PIPE_W + BLOCK_BORDER_W * (PIPE_W - 1))
#define P_HGT   (BLOCK_H * PIPE_H + BLOCK_BORDER_H * (PIPE_H - 1))
#define PR_WDT  (BLOCK_W * PREVIEW_W + BLOCK_BORDER_W * (PREVIEW_W - 1))
#define PR_HGT  (BLOCK_H * PREVIEW_H + BLOCK_BORDER_H * (PREVIEW_H - 1))

#define S_WDT \
  MAX( \
    4 * PIPE_EDGE_W + 2 * H_SEP_BUFFER + P_WDT + PR_WDT, \
    TEXT_X + TEXT_X_SEP + 6 * zero_w + score_w + H_SEP_BUFFER \
  )

#define S_HGT (2 * PIPE_EDGE_H + P_HGT)

#define TEXT_X      (2 * PIPE_EDGE_W + P_WDT + H_SEP_BUFFER)
#define TEXT_Y      (P_HGT - 7 * BLOCK_H)
#define TEXT_X_SEP  20
#define TEXT_Y_SEP  5

#define PREVIEW_PANE_LEFT_EDGE = SCREEN_LEFT_EDGE + 2 * PIPE_EDGE_W + PIPE_W + H_SEP_BUFFER;

#define DEFAULT_FONT "Amerika Sans.ttf"

extern char *font_string;
extern int display_tetris, preview_pane_left_edge, score_w, zero_w, font_h;
extern Uint32 level_colors[21][7];
extern char *level_names[21];
extern SDL_Surface *screen, *level_text, *lines_text, *score_text;
extern TTF_Font *font;

void DrawBox(int left_x, int right_x, int upper_y, int lower_y), 
  InitializeDisplay(),
  UpdateDisplay(),
  TerminateDisplay(),
  NukeLines(),
  PauseDisplay();

#endif
