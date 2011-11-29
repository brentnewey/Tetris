#include "display_ncurses.h"

static WINDOW *screen;
bool display_tetris;
int preview_pane_left_edge;

void InitializeDisplay(int left_edge) {
  preview_pane_left_edge = left_edge;
}

void DrawBox(int left_x, int right_x, int upper_y, int lower_y){

  // Draw corners.
  mvwaddch(screen, upper_y, left_x, PIPE_CORNER_TEXTURE);
  mvwaddch(screen, upper_y, right_x, PIPE_CORNER_TEXTURE);
  mvwaddch(screen, lower_y, left_x, PIPE_CORNER_TEXTURE);
  mvwaddch(screen, lower_y, right_x, PIPE_CORNER_TEXTURE);

  // Draw left & right edges.
  for(int i = upper_y + 1; i < lower_y; i++){
    mvwaddch(screen, i, left_x, PIPE_VERTICAL_BOUNDARY_TEXTURE);
    mvwaddch(screen, i, right_x, PIPE_VERTICAL_BOUNDARY_TEXTURE);
  }

  // Draw top & bottom edges.
  for(int i = left_x + 1; i < right_x; i++){
    mvwaddch(screen, upper_y, i, PIPE_HORIZONTAL_BOUNDARY_TEXTURE);
    mvwaddch(screen, lower_y, i, PIPE_HORIZONTAL_BOUNDARY_TEXTURE);
  }

}

void DrawPlayingArea(){

  screen = initscr();
  start_color(); // For the tetrads.
  noecho(); // Because I use the z/x/c and space keys
  cbreak(); // Do not require enter to be pressed to get input
  nodelay(screen, TRUE); //Don't have getch block

  //pair indeces are offset because 0 cannot be changed
  init_pair(tetrad_cross + 1, COLOR_BLUE, COLOR_BLUE);
  init_pair(tetrad_line + 1, COLOR_GREEN, COLOR_GREEN);
  init_pair(tetrad_square + 1, COLOR_RED, COLOR_RED);
  init_pair(tetrad_z + 1, COLOR_YELLOW, COLOR_YELLOW);
  init_pair(tetrad_s + 1, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(tetrad_l + 1, COLOR_CYAN, COLOR_CYAN);
  init_pair(tetrad_reverse_l + 1, COLOR_WHITE, COLOR_WHITE);

  curs_set(0); // Take the cursor off the screen

  // Draw the main tetris playing field.
  DrawBox(SCREEN_LEFT_EDGE, SCREEN_LEFT_EDGE + PIPE_EDGE_WIDTH + PIPE_W,
	   SCREEN_TOP_EDGE, SCREEN_TOP_EDGE + PIPE_EDGE_HEIGHT + PIPE_H);
  
  // Draw the preview pane.
  DrawBox(preview_pane_left_edge,
	   preview_pane_left_edge + PIPE_EDGE_WIDTH + PREVIEW_W,
	   SCREEN_TOP_EDGE,
	   SCREEN_TOP_EDGE + PIPE_EDGE_HEIGHT + PREVIEW_H);

  // TEMP


}


void UpdateDisplay() {

  // Update the main tetris playing field.
  for(int i = 0; i < PIPE_H; i++){
    for(int j = 0; j < PIPE_W; j++){
      if(empty_tile == grid[j][i])
	mvwaddch(screen, SCREEN_TOP_EDGE + PIPE_EDGE_HEIGHT + i,
		 SCREEN_LEFT_EDGE + PIPE_EDGE_WIDTH + j, EMPTY_TILE_TEXTURE);
      else
	mvwaddch(screen, SCREEN_TOP_EDGE + PIPE_EDGE_HEIGHT + i, 
		 SCREEN_LEFT_EDGE + PIPE_EDGE_WIDTH + j,
		 TETRAD_TILE_TEXTURE 
		 | COLOR_PAIR((grid[j][i] - 1) / TETRAD_TILE_TYPE_COUNT + 1)
		 );
    }
  }
  
  // Update the preview pane.
  for(int i = 0; i < PREVIEW_H; i++){
    for(int j = 0; j < PREVIEW_W ; j++){
      if(empty_tile != next_grid[j][i]) 
	mvwaddch(screen, SCREEN_TOP_EDGE + PIPE_EDGE_HEIGHT + i,
		 preview_pane_left_edge + PIPE_EDGE_WIDTH + j,
		 TETRAD_TILE_TEXTURE 
		 | COLOR_PAIR((next_grid[j][i] - 1)
			      / TETRAD_TILE_TYPE_COUNT + 1)
		 );
      else mvwaddch(screen, SCREEN_TOP_EDGE + PIPE_EDGE_HEIGHT + i,
		    preview_pane_left_edge + PIPE_EDGE_WIDTH + j,
		    EMPTY_TILE_TEXTURE);
    }
  }

  //TEMP
  mvwprintw(screen, 22, 0, "               ");
  mvwprintw(screen, 18, 14, "Score %d", score);
  mvwprintw(screen, 19, 14, "Level %d", level);
  mvwprintw(screen, 20, 14, "Lines %d", lines_cleared);

  if(display_tetris) mvwprintw(screen, 7, 14, "Tetris!");
  else mvwprintw(screen, 7, 14, "       ");

}
