#ifndef INC_PIPE_H
#define INC_PIPE_H

#include <stdlib.h>

/* The size of the pipe */
#define PIPE_W 10
#define PIPE_BUFFER_H 5
#define PIPE_H 20

/* The size of the preivew pane */
#define PREVIEW_W 6
#define PREVIEW_H 4

/* Used to decode a tile. Divide the tile value by this to get the tetrad type.
   Mod the tile value with this to get the tile type. */

#define TETRAD_TILE_TYPE_COUNT 3

#define TETRAD_TYPE_COUNT 7

/* The number of tiles in a tetrad */
#define TETRAD_TILE_COUNT 4
#define TETRAD_PIVOT_COUNT 1
#define NUMBER_OF_COORDINATES 2
#define NUMBER_OF_ORIENTATIONS 4


/* cx, cy = pivot coordinates
   sXx, sXy = other three squares coordinates
   sXt = display type for square */
extern int current_tetrad, next_tetrad,
  current_orientation, cx, cy, s1x, s2x, s3x, s1y, s2y, s3y, s1t, s2t, s3t,
  s4t, pipe_last_x, pipe_last_y, score, level, lines_cleared;

extern int grid[PIPE_W][PIPE_H],
  next_grid[PREVIEW_W][PREVIEW_H],
  buffer_grid[PIPE_W][PIPE_BUFFER_H];

struct tetrad_orientation {
  int s1x, s1y, s2x, s2y, s3x, s3y;
};

struct tetrad_definition {
  struct tetrad_orientation orientations[NUMBER_OF_ORIENTATIONS];
  int cx, cy;
};

enum tile_types {
  empty_tile = 0, pivot_tile = 1, standard_tile = 2, solid_tile = 3
};

enum tetrad_types {
  tetrad_null = -1, tetrad_cross = 0, tetrad_line = 1, tetrad_square = 2,
  tetrad_z = 3, tetrad_s = 4, tetrad_l = 6, tetrad_reverse_l = 5
};

enum orientations {
  base = 0, clockwise = 1, flipped = 2, counter_clockwise = 3
};

extern struct tetrad_definition tetrad_definitions[TETRAD_TYPE_COUNT];

void ShiftTetradDown(),
  ShiftTetradLeft(),
  ShiftTetradRight(),
  SetProposedTetrad(int new_orientation),
  WriteProposedTetrad(int new_orientation),
  RotateClockwise(),
  RotateCounterClockwise(),
  Flip(),
  SolidifyTetrad();

int IsActiveTile(int tile_value),
  IsSolidTile(int tile_value),
  MadeContact(),
  AgainstLeftWall(),
  AgainstRightWall(),
  ValidateProposedTetrad(),
  ShiftOrientation(int old_orientation, int rotates),
  GenerateTetrad(),
  ClearLines(void),
  IsLineFull(int line);

#endif
