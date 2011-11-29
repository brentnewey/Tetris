#include "pipe.h"

void ShiftTetradDown() {
  int i, j;

  s1y++; s2y++; s3y++; cy++;

  for(i = 0; i < PIPE_W; i++){

    for(j = pipe_last_y; j >= 0; j--){
      if(cx == i && cy == j)
	grid[i][j] = pivot_tile + current_tetrad * TETRAD_TILE_TYPE_COUNT;
      else if((s1x == i && s1y == j) || (s2x == i && s2y == j) || 
	      (s3x == i && s3y == j))
	grid[i][j] = standard_tile + current_tetrad * TETRAD_TILE_TYPE_COUNT;
      else if(solid_tile % TETRAD_TILE_TYPE_COUNT 
	      != grid[i][j] % TETRAD_TILE_TYPE_COUNT)
	grid[i][j] = empty_tile;
    }
  }
}

void ShiftTetradLeft() {
  int i, j;
  for(i = 0; i < PIPE_W; i++){
    for(j = 0; j < PIPE_H; j++){
      if(empty_tile != grid[i][j] && 
	 solid_tile % TETRAD_TILE_TYPE_COUNT 
	 != grid[i][j] % TETRAD_TILE_TYPE_COUNT){
	grid[i-1][j] = grid[i][j];
	grid[i][j] = empty_tile;
      }
    }
  }
  s1x--;s2x--; s3x--; cx--;
}

void ShiftTetradRight() {
  int i, j;
  /* If we work backward we'll never overwrite blocks. */
  for(i = pipe_last_x; i >= 0; i--){
    for(j = 0; j < PIPE_H; j++){
      if(empty_tile != grid[i][j] &&
	 solid_tile % TETRAD_TILE_TYPE_COUNT 
	 != grid[i][j] % TETRAD_TILE_TYPE_COUNT){
	grid[i+1][j] = grid[i][j];
	grid[i][j] = empty_tile;
      }
    }
  }
  s1x++; s2x++; s3x++; cx++;
}

int IsActiveTile(int tile_value) {
  return (empty_tile != tile_value 
	  && solid_tile % TETRAD_TILE_TYPE_COUNT
	  != tile_value % TETRAD_TILE_TYPE_COUNT);
}

int IsSolidTile(int tile_value) {
  return (empty_tile != tile_value 
	  && solid_tile % TETRAD_TILE_TYPE_COUNT
	  == tile_value % TETRAD_TILE_TYPE_COUNT);
}

int MadeContact() {
  int i, j;
  for(i = 0; i < PIPE_W; i++){
    for(j = 0; j < PIPE_H; j++){
      if(IsActiveTile(grid[i][j]) &&
	 (pipe_last_y == j || IsSolidTile(grid[i][j+1])))
      return 1;
    }
  }
  return 0;
}

int AgainstLeftWall() {
  int i, j;
  for(i = 0; i < PIPE_W; i++){
    for(j = 0; j < PIPE_H; j++){
      if(IsActiveTile(grid[i][j]) &&
	 (0 == i || IsSolidTile(grid[i-1][j]))) 
	return 1;
    }
  }
  return 0;
}

int AgainstRightWall() {
  int i, j;
  for(i = 0; i < PIPE_W; i++){
    for(j = 0; j < PIPE_H; j++){
      if(IsActiveTile(grid[i][j]) &&
	 (pipe_last_x == i || IsSolidTile(grid[i+1][j]))) 
	return 1;
    }
  }
  return 0;
}

void SetProposedTetrad(int new_orientation){
  struct tetrad_orientation new_piece
    = tetrad_definitions[current_tetrad].orientations[new_orientation];

  s1x = cx + new_piece.s1x;
  s1y = cy + new_piece.s1y;
  s2x = cx + new_piece.s2x;
  s2y = cy + new_piece.s2y;
  s3x = cx + new_piece.s3x;
  s3y = cy + new_piece.s3y;

  s1t = s2t = s3t = current_tetrad * TETRAD_TILE_TYPE_COUNT + standard_tile;
  s4t = current_tetrad * TETRAD_TILE_TYPE_COUNT + pivot_tile;

}

int ValidateProposedTetrad() {

  if(
     s1x < 0 || s1x > pipe_last_x || s2x < 0 || s2x > pipe_last_x ||
     s3x < 0 || s3x > pipe_last_x || s1y > pipe_last_y ||
     s2y > pipe_last_y || s3y > pipe_last_y ||
     (IsSolidTile(grid[s1x][s1y]) && s1y >= 0) ||
     (IsSolidTile(grid[s2x][s2y]) && s2y >= 0) ||
     (IsSolidTile(grid[s3x][s3y]) && s3y >= 0)
     )
  return(0);
  else return(1);
}

void WriteProposedTetrad(int new_orientation) {
  int i, j;
  for(i = 0; i < PIPE_W; i++) {
    for(j = 0; j < PIPE_H; j++){
      if(i == s1x && j == s1y) grid[i][j] = s1t;
      else if(i == s2x && j == s2y) grid[i][j] = s2t;
      else if(i == s3x && j == s3y) grid[i][j] = s3t;
      else if(i == cx && j == cy) grid[i][j] = s4t;    
      else if(solid_tile % TETRAD_TILE_TYPE_COUNT !=
	      grid[i][j] % TETRAD_TILE_TYPE_COUNT)
	grid[i][j] = empty_tile;
    }
  }
  current_orientation = new_orientation;
}

int ShiftOrientation(int old_orientation, int rotates) {
  int new_orientation = current_orientation + rotates;
  while(new_orientation > counter_clockwise) {
    new_orientation -= NUMBER_OF_ORIENTATIONS;
  }
  while(new_orientation < base) {
    new_orientation += NUMBER_OF_ORIENTATIONS;
  }
  return new_orientation;
}

void RotateClockwise() {
  int new_orientation = ShiftOrientation(current_orientation, 1);
  SetProposedTetrad(new_orientation);
  if(ValidateProposedTetrad()) WriteProposedTetrad(new_orientation);
  else SetProposedTetrad(current_orientation);
}

void RotateCounterClockwise() {
  int new_orientation = ShiftOrientation(current_orientation, -1);
  SetProposedTetrad(new_orientation);
  if(ValidateProposedTetrad()) WriteProposedTetrad(new_orientation);
  else SetProposedTetrad(current_orientation);
}

void Flip() {
  int new_orientation = ShiftOrientation(current_orientation, 2);
  SetProposedTetrad(new_orientation);
  if(ValidateProposedTetrad()) WriteProposedTetrad(new_orientation);
  else SetProposedTetrad(current_orientation);
}

void SolidifyTetrad() {
  int i, j;
  for(i = 0 ; i < PIPE_W; i++){
    for(j = 0 ; j < PIPE_H; j++){
      if(pivot_tile == grid[i][j] % TETRAD_TILE_TYPE_COUNT)
	grid[i][j] += TETRAD_TILE_TYPE_COUNT - pivot_tile;
      if(standard_tile == grid[i][j] % TETRAD_TILE_TYPE_COUNT)
	grid[i][j] += TETRAD_TILE_TYPE_COUNT - standard_tile;
    }
  }
}

int GenerateTetrad() {
  struct tetrad_orientation new_tetrad;
  int m, i, j, px, py;

  if(tetrad_null == current_tetrad)
    current_tetrad = rand() % TETRAD_TYPE_COUNT;
  else current_tetrad = next_tetrad;
  next_tetrad = rand() % TETRAD_TYPE_COUNT;
  current_orientation = base;
  new_tetrad = tetrad_definitions[current_tetrad].orientations[base];
  cx = tetrad_definitions[current_tetrad].cx;
  cy = tetrad_definitions[current_tetrad].cy;

  if(IsSolidTile(grid[cx][cy]) ||
     IsSolidTile(grid[cx + new_tetrad.s1x][cy + new_tetrad.s1y]) ||
     IsSolidTile(grid[cx + new_tetrad.s2x][cy + new_tetrad.s2y]) ||
     IsSolidTile(grid[cx + new_tetrad.s3x][cy + new_tetrad.s3y]))
    return 0;

  m = current_tetrad * TETRAD_TILE_TYPE_COUNT;
  grid[cx][cy] = m + pivot_tile;
  grid[cx + new_tetrad.s1x][cy + new_tetrad.s1y] =
    grid[cx + new_tetrad.s2x][cy + new_tetrad.s2y] =
    grid[cx + new_tetrad.s3x][cy + new_tetrad.s3y] =
    m + standard_tile;

  s1x = cx + new_tetrad.s1x;
  s2x = cx + new_tetrad.s2x;
  s3x = cx + new_tetrad.s3x;
  s1y = cy + new_tetrad.s1y;
  s2y = cy + new_tetrad.s2y;
  s3y = cy + new_tetrad.s3y;

  for(i = 0; i < PREVIEW_W; i++){
    for(j = 0; j < PREVIEW_H; j++){
      next_grid[i][j] = empty_tile;
    }
  }

  px = tetrad_definitions[next_tetrad].cx - 2;
  py = tetrad_definitions[next_tetrad].cy + 1;
  m = next_tetrad * TETRAD_TILE_TYPE_COUNT;
  new_tetrad = tetrad_definitions[next_tetrad].orientations[base];

  next_grid[px][py] = next_grid[px + new_tetrad.s1x][py + new_tetrad.s1y] =
    next_grid[px + new_tetrad.s2x][py + new_tetrad.s2y] =
    next_grid[px + new_tetrad.s3x][py + new_tetrad.s3y] =
    m + standard_tile;

  return 1;
}

int ClearLines(void) {
  int current_line = pipe_last_y, current_lines_cleared = 0;
  int clear_this_line, i, stack_to_clear;

  while(current_line){
    clear_this_line = 1;

    for(i = 0; i < PIPE_W; i++)
      if(empty_tile == grid[i][current_line]) clear_this_line = 0;

    if(clear_this_line) {
      for(i = 0; i < PIPE_W; i++)
	grid[i][current_line] = empty_tile;
   
      stack_to_clear = current_line - 1;

      while(stack_to_clear){
	for(i = 0; i < PIPE_W; i++)
	  grid[i][stack_to_clear+1] = grid[i][stack_to_clear];
	stack_to_clear--;
      }
      current_lines_cleared++;
    }
    else current_line--;
  }
  return(current_lines_cleared);
}

int IsLineFull(int line) {
	int is_full = 1;
	int i;
    for(i = 0; i < PIPE_W; i++)
      if(empty_tile == grid[i][line]) is_full = 0;
	return is_full;
}

