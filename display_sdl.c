#include "display_sdl.h"

SDL_Color textColor = {255, 255, 255};

void SetPixel2(int x, int y, Uint32 color) {
  Uint32 *pixmem32;
  pixmem32 = (Uint32*) screen->pixels + (S_WDT * y) + x;
  *pixmem32 = color;
}

void InitializeDisplay(char *font_string){

  SDL_Rect draw, type;

	level_colors[0][tetrad_cross] = 0x0000FF;
	level_colors[0][tetrad_square] = 0x0000DD;
	level_colors[0][tetrad_z] = 0x0077BB;
	level_colors[0][tetrad_l] = 0x0099DD;
	level_colors[0][tetrad_reverse_l] = 0x0000BB;
	level_colors[0][tetrad_line] = 0xBBBBBB;
	level_colors[0][tetrad_s] = 0x000099;
  level_names[0] = "Blue Steel";

	level_colors[1][tetrad_cross] = 0xFF0000;
	level_colors[1][tetrad_square] = 0xBB0077;
	level_colors[1][tetrad_z] = 0xDD0000;
	level_colors[1][tetrad_l] = 0xDD0099;
	level_colors[1][tetrad_reverse_l] = 0xBB0000;
	level_colors[1][tetrad_line] = 0xBBBBBB;
	level_colors[1][tetrad_s] = 0x990000;
  level_names[1] = "Fuchsion";

	level_colors[2][tetrad_cross] = 0x00FF00;
	level_colors[2][tetrad_square] = 0x77BB00;
	level_colors[2][tetrad_z] = 0x00DD00;
	level_colors[2][tetrad_l] = 0x99DD00;
	level_colors[2][tetrad_reverse_l] = 0x00BB00;
	level_colors[2][tetrad_line] = 0xBBBBBB;
	level_colors[2][tetrad_s] = 0x009900;
  level_names[2] = "Other Side";

	level_colors[3][tetrad_cross] = 0xFF9900;
	level_colors[3][tetrad_square] = 0xDD7700;
	level_colors[3][tetrad_z] = 0xFF5500;
	level_colors[3][tetrad_l] = 0xDD3300;
	level_colors[3][tetrad_reverse_l] = 0xAA9900;
	level_colors[3][tetrad_line] = 0xBBBBBB;
	level_colors[3][tetrad_s] = 0x99AA00;
  level_names[3] = "Autumn Leaves";

	level_colors[4][tetrad_cross] = 0x00FF99;
	level_colors[4][tetrad_square] = 0x00DD77;
	level_colors[4][tetrad_z] = 0x00FF55;
	level_colors[4][tetrad_l] = 0x00DD33;
	level_colors[4][tetrad_reverse_l] = 0x00AA99;
	level_colors[4][tetrad_line] = 0xBBBBBB;
	level_colors[4][tetrad_s] = 0x0099AA;
  level_names[4] = "Reflections";

	level_colors[5][tetrad_cross] = 0x9900FF;
	level_colors[5][tetrad_square] = 0x7700DD;
	level_colors[5][tetrad_z] = 0x5500FF;
	level_colors[5][tetrad_l] = 0x3300DD;
	level_colors[5][tetrad_reverse_l] = 0x9900AA;
	level_colors[5][tetrad_line] = 0xBBBBBB;
	level_colors[5][tetrad_s] = 0xAA0099;

	level_colors[6][tetrad_cross] = 0x775500;
	level_colors[6][tetrad_square] = 0xBB9900;
	level_colors[6][tetrad_z] = 0x997700;
	level_colors[6][tetrad_l] = 0xDDBB00;
	level_colors[6][tetrad_reverse_l] = 0x886600;
	level_colors[6][tetrad_line] = 0xBBBBBB;
	level_colors[6][tetrad_s] = 0xAA8800;

	level_colors[7][tetrad_cross] = 0x999999;
	level_colors[7][tetrad_square] = 0x777777;
	level_colors[7][tetrad_z] = 0x555555;
	level_colors[7][tetrad_l] = 0xAAAAAA;
	level_colors[7][tetrad_reverse_l] = 0x333333;
	level_colors[7][tetrad_line] = 0xBBBBBB;
	level_colors[7][tetrad_s] = 0xCCCCCC;

	level_colors[8][tetrad_cross] = 0x0000FF;
	level_colors[8][tetrad_square] = 0x0000BB;
	level_colors[8][tetrad_z] = 0x000077;
	level_colors[8][tetrad_l] = 0xBBBB00;
	level_colors[8][tetrad_reverse_l] = 0x777700;
	level_colors[8][tetrad_line] = 0xBBBBBB;
	level_colors[8][tetrad_s] = 0x333300;

	level_colors[9][tetrad_cross] = 0xFF0000;
	level_colors[9][tetrad_square] = 0x00FF00;
	level_colors[9][tetrad_z] = 0x0000FF;
	level_colors[9][tetrad_l] = 0xBBBB00;
	level_colors[9][tetrad_reverse_l] = 0xBB00BB;
	level_colors[9][tetrad_line] = 0xBBBBBB;
	level_colors[9][tetrad_s] = 0x00BBBB;

	level_colors[10][tetrad_cross] = 0xFF0000;
	level_colors[10][tetrad_square] = 0xDD0000;
	level_colors[10][tetrad_z] = 0xBB0000;
	level_colors[10][tetrad_l] = 0xDDDDDD;
	level_colors[10][tetrad_reverse_l] = 0x999999;
	level_colors[10][tetrad_line] = 0xBBBBBB;
	level_colors[10][tetrad_s] = 0x777777;

	level_colors[11][tetrad_cross] = 0x000000;
	level_colors[11][tetrad_square] = 0x000000;
	level_colors[11][tetrad_z] = 0x000000;
	level_colors[11][tetrad_l] = 0x000000;
	level_colors[11][tetrad_reverse_l] = 0x000000;
	level_colors[11][tetrad_line] = 0x000000;
	level_colors[11][tetrad_s] = 0x000000;

	srand((unsigned int)time(NULL));
	level_colors[12][tetrad_cross] = rand() % 0xFF + 0x100 * (rand() % 0xFF) + 0x10000 * (rand() % 0xFF);
	level_colors[12][tetrad_square] = rand() % 0xFF + 0x100 * (rand() % 0xFF) + 0x10000 * (rand() % 0xFF);
	level_colors[12][tetrad_z] = rand() % 0xFF + 0x100 * (rand() % 0xFF) + 0x10000 * (rand() % 0xFF);
	level_colors[12][tetrad_l] = rand() % 0xFF + 0x100 * (rand() % 0xFF) + 0x10000 * (rand() % 0xFF);
	level_colors[12][tetrad_reverse_l] = rand() % 0xFF + 0x100 * (rand() % 0xFF) + 0x10000 * (rand() % 0xFF);
	level_colors[12][tetrad_line] = 0xBBBBBB;
	level_colors[12][tetrad_s] = rand() % 0xFF + 0x100 * (rand() % 0xFF) + 0x10000 * (rand() % 0xFF);

	level_colors[13][tetrad_cross] = 0x775500;
	level_colors[13][tetrad_square] = 0x997700;
	level_colors[13][tetrad_z] = 0x886600;
	level_colors[13][tetrad_l] = 0x557700;
	level_colors[13][tetrad_reverse_l] = 0x335500;
	level_colors[13][tetrad_line] = 0xBBBBBB;
	level_colors[13][tetrad_s] = 0x113300;

	level_colors[14][tetrad_cross] = 0x0000BB;
	level_colors[14][tetrad_square] = 0x00BB77;
	level_colors[14][tetrad_z] = 0x00BBBB;
	level_colors[14][tetrad_l] = 0x000077;
	level_colors[14][tetrad_reverse_l] = 0x007733;
	level_colors[14][tetrad_line] = 0xBBBBBB;
	level_colors[14][tetrad_s] = 0x007777;

	level_colors[15][tetrad_cross] = 0xFFFFFF;
	level_colors[15][tetrad_square] = 0xFFFFFF;
	level_colors[15][tetrad_z] = 0xFFFFFF;
	level_colors[15][tetrad_l] = 0xFFFFFF;
	level_colors[15][tetrad_reverse_l] = 0xFFFFFF;
	level_colors[15][tetrad_line] = 0xFFFFFF;
	level_colors[15][tetrad_s] = 0xFFFFFF;

	level_colors[16][tetrad_cross] = 0xBB0000;
	level_colors[16][tetrad_square] = 0x7700BB;
	level_colors[16][tetrad_z] = 0xBB00BB;
	level_colors[16][tetrad_l] = 0x770000;
	level_colors[16][tetrad_reverse_l] = 0x330077;
	level_colors[16][tetrad_line] = 0xBBBBBB;
	level_colors[16][tetrad_s] = 0x770077;

	level_colors[17][tetrad_cross] = 0xBBBBFF;
	level_colors[17][tetrad_square] = 0xAAAAEE;
	level_colors[17][tetrad_z] = 0x9999DD;
	level_colors[17][tetrad_l] = 0x8888CC;
	level_colors[17][tetrad_reverse_l] = 0x7777BB;
	level_colors[17][tetrad_line] = 0xBBBBBB;
	level_colors[17][tetrad_s] = 0x6666AA;

	level_colors[18][tetrad_cross] = 0xFF0000;
	level_colors[18][tetrad_square] = 0x0000FF;
	level_colors[18][tetrad_z] = 0xFFFF00;
	level_colors[18][tetrad_l] = 0xFF0000;
	level_colors[18][tetrad_reverse_l] = 0x0000FF;
	level_colors[18][tetrad_line] = 0xBBBBBB;
	level_colors[18][tetrad_s] = 0xFFFF00;

	level_colors[19][tetrad_cross] = 0xFF00FF;
	level_colors[19][tetrad_square] = 0xBB00BB;
	level_colors[19][tetrad_z] = 0xFF22FF;
	level_colors[19][tetrad_l] = 0x00BB00;
	level_colors[19][tetrad_reverse_l] = 0x00FF00;
	level_colors[19][tetrad_line] = 0xBBBBBB;
	level_colors[19][tetrad_s] = 0x22FF22;

	level_colors[20][tetrad_cross] = 0xFF2200;
	level_colors[20][tetrad_square] = 0xDD4400;
	level_colors[20][tetrad_z] = 0xFF6600;
	level_colors[20][tetrad_l] = 0xFF6622;
	level_colors[20][tetrad_reverse_l] = 0xFFAA44;
	level_colors[20][tetrad_line] = 0xBBBBBB;
	level_colors[20][tetrad_s] = 0xDD8822;

  SDL_Init(SDL_INIT_VIDEO);

  TTF_Init();


  font = TTF_OpenFont((strlen(font_string) > 0 ? font_string : DEFAULT_FONT), 22);
  TTF_SizeText(font, "Score", &score_w, &font_h);
  TTF_SizeText(font, "0", &zero_w, &font_h);

  screen = SDL_SetVideoMode(S_WDT, S_HGT, 0, SDL_SWSURFACE);

  draw.x = SCREEN_LEFT_EDGE;
  draw.y = SCREEN_TOP_EDGE;
  draw.h = 2 * PIPE_EDGE_H + P_HGT;
  draw.w = 2 * PIPE_EDGE_W + P_WDT;
  SDL_FillRect(screen, &draw, 0xFFFFFF);

  draw.x 
    = SCREEN_LEFT_EDGE + 2 * PIPE_EDGE_W + P_WDT + H_SEP_BUFFER;

  draw.y = SCREEN_TOP_EDGE + V_SEP_BUFFER;
  draw.h = 2 * PIPE_EDGE_H + PR_HGT;
  draw.w = 2 * PIPE_EDGE_W + PR_WDT;
  SDL_FillRect(screen, &draw, 0xFFFFFF);

  level_text = TTF_RenderText_Solid(font, "Level", textColor);
  lines_text = TTF_RenderText_Solid(font, "Lines", textColor);
  score_text = TTF_RenderText_Solid(font, "Score", textColor);

  type.x = TEXT_X;
  type.y = TEXT_Y;
  SDL_BlitSurface(level_text, NULL, screen, &type);
  type.y = TEXT_Y + font_h + TEXT_Y_SEP;
  SDL_BlitSurface(lines_text, NULL, screen, &type);
  type.y = TEXT_Y + 2 * (font_h + TEXT_Y_SEP);
  SDL_BlitSurface(score_text, NULL, screen, &type);

  SDL_FreeSurface(level_text);
  SDL_FreeSurface(lines_text);
  SDL_FreeSurface(score_text);

}


void UpdateDisplay() {

  int i, j, k;
  SDL_Rect draw;
  char level_chr[5], lines_chr[4], score_chr[10];
  SDL_Rect type;

  draw.x = SCREEN_LEFT_EDGE + PIPE_EDGE_W;
  draw.y = SCREEN_TOP_EDGE + PIPE_EDGE_H;
  draw.h = P_HGT;
  draw.w = P_WDT;

  /* Clear view */
  SDL_FillRect(screen, &draw, 0x000000);

  draw.x = TEXT_X + score_w + TEXT_X_SEP;
  draw.y = TEXT_Y;
  draw.h = 3 * font_h + 2 * TEXT_Y_SEP;
  draw.w = 10 * zero_w;
  SDL_FillRect(screen, &draw, 0x000000);

  /* Update the main tetris playing field. */
  for(i = 0; i < PIPE_H; i++){
    for(j = 0; j < PIPE_W; j++){
      if(empty_tile != grid[j][i]) {
	
	int tetrad = (grid[j][i] - 1) / TETRAD_TILE_TYPE_COUNT;
	int t_type = grid[j][i] % TETRAD_TILE_TYPE_COUNT;
	int top = grid[j][i - 1];
	int bottom = grid[j][i + 1];
	int left = grid[j - 1][i];
	int right = grid[j + 1][i];
	
	draw.x = 
	  SCREEN_LEFT_EDGE + PIPE_EDGE_W + (BLOCK_W + BLOCK_BORDER_W) * j;
	draw.y 
	  = SCREEN_TOP_EDGE + PIPE_EDGE_H + (BLOCK_H + BLOCK_BORDER_H) * i;
	draw.h = BLOCK_H;
	draw.w = BLOCK_W;
	SDL_FillRect(screen, &draw, level_colors[level][tetrad]);
	
	/* Corners (only handles top left corner, but that's all we need, 
	   since it is a communal corner) */

	if(
	   (
	    !(
	      0 == i || 
	      tetrad != (grid[j][i - 1] - 1) / TETRAD_TILE_TYPE_COUNT || 
	      empty_tile == grid[j][i - 1]
	      )
	    )
	   && 
	   (
	    !(
	      0 == j || 
	      tetrad != (grid[j - 1][i] - 1) / TETRAD_TILE_TYPE_COUNT || 
	      empty_tile == grid[j - 1][i]
	      )
	    )
	   && 
	   (
	    !(
	      (0 == i && j == 0) || 
	      tetrad != (grid[j - 1][i - 1] - 1) / TETRAD_TILE_TYPE_COUNT || 
	      empty_tile == grid[j - 1][i - 1]
	      )
	    )
	   )
	  SetPixel2(
		    draw.x - BLOCK_BORDER_W, 
		    draw.y - BLOCK_BORDER_H, 
		    level_colors[level][tetrad]
		    );

	/* Top Border */
		    if(0 == i || tetrad != (top - 1) / TETRAD_TILE_TYPE_COUNT || empty_tile == top || ((pivot_tile == top % TETRAD_TILE_TYPE_COUNT || standard_tile == top % TETRAD_TILE_TYPE_COUNT) && 0 == t_type) || ((pivot_tile == t_type || standard_tile == t_type) && 0 ==  top % TETRAD_TILE_TYPE_COUNT))
			    for(k = 0 - BLOCK_BORDER_W; k < BLOCK_W + BLOCK_BORDER_W; k++)
 				    SetPixel2(draw.x + k, draw.y - BLOCK_BORDER_H, 0xFFFFFF);
		    else
			    for(k = 0; k < BLOCK_W; k++)
 				    SetPixel2(draw.x + k, draw.y - BLOCK_BORDER_H, level_colors[level][tetrad]);

		    /* Bottom Border */
		    if((PIPE_H - 1) == i || empty_tile == bottom)
			    for(k = 0 - BLOCK_BORDER_W; k < BLOCK_W + BLOCK_BORDER_W; k++)
				    SetPixel2(draw.x + k , draw.y + BLOCK_BORDER_H + BLOCK_H - 1, 0xFFFFFF);
		    else
			    for(k = 0; k < BLOCK_W; k++)
 				    SetPixel2(draw.x + k, draw.y + BLOCK_BORDER_H + BLOCK_H - 1, level_colors[level][tetrad]);

		    /* Left Border */
		    if(0 == j || tetrad != (left - 1) / TETRAD_TILE_TYPE_COUNT || empty_tile == left || ((pivot_tile == left % TETRAD_TILE_TYPE_COUNT || standard_tile == left % TETRAD_TILE_TYPE_COUNT) && 0 == t_type) || ((pivot_tile == t_type || standard_tile == t_type) && 0 == left % TETRAD_TILE_TYPE_COUNT))
			    for(k = 0 - BLOCK_BORDER_H; k < BLOCK_H + BLOCK_BORDER_H; k++)
				    SetPixel2(draw.x - BLOCK_BORDER_W, draw.y + k, 0xFFFFFF);
		    else
			    for(k = 0; k < BLOCK_H; k++)
 				    SetPixel2(draw.x - BLOCK_BORDER_W, draw.y + k, level_colors[level][tetrad]);

		    /* Right Border */
		    if((PIPE_W - 1) == j || empty_tile == right)
			    for(k = 0 - BLOCK_BORDER_H; k < BLOCK_H + BLOCK_BORDER_H; k++)
				    SetPixel2(draw.x + BLOCK_BORDER_W + BLOCK_W - 1, draw.y + k, 0xFFFFFF);
		    else
			    for(k = 0; k < BLOCK_H; k++)
 				    SetPixel2(draw.x + BLOCK_BORDER_W + BLOCK_W - 1, draw.y + k, level_colors[level][tetrad]);

      }
    }
  }
  
  draw.x = SCREEN_LEFT_EDGE + 3 * PIPE_EDGE_W + P_WDT + H_SEP_BUFFER;
  draw.y = SCREEN_TOP_EDGE + PIPE_EDGE_H + V_SEP_BUFFER;
  draw.h = PR_HGT;
  draw.w = PR_WDT;

  /* Clear view */
  SDL_FillRect(screen, &draw, 0x000000);
  
  /* Update the preview pane. */
  for(i = 0; i < PREVIEW_H; i++){
    for(j = 0; j < PREVIEW_W ; j++){
      if(empty_tile != next_grid[j][i]){

	      int tetrad = (next_grid[j][i] - 1) / TETRAD_TILE_TYPE_COUNT;
	      int block_w, block_h;
	      int block_h_o = 0;

	      switch(tetrad) {
		      case tetrad_cross:		  block_w = 3;
								                  block_h = 2;
								                  break;

		      case tetrad_line:		    block_w = 4;
								                  block_h = 1;
								                  break;

		      case tetrad_square:		  block_w = 2;
								                  block_h = 2;
								                  block_h_o = 2;
								                  break;

		      case tetrad_z:			    block_w = 3;
								                  block_h = 2;
								                  break;

		      case tetrad_s:			    block_w = 3;
								                  block_h = 2;
								                  break;

		      case tetrad_l:			    block_w = 3;
								                  block_h = 2;
								                  break;

		      case tetrad_reverse_l:	block_w = 3;
								                  block_h = 2;
								                  break;

	      }

	      draw.x = 
	        SCREEN_LEFT_EDGE + 
	        3 * PIPE_EDGE_W + 
	        P_WDT + 
	        H_SEP_BUFFER + 
	        (BLOCK_W + BLOCK_BORDER_W) * j +
	        BLOCK_W * (4 - (block_h_o + block_w)) / 2;

	      draw.y = 
	        SCREEN_TOP_EDGE +
	        PIPE_EDGE_H +
	        V_SEP_BUFFER +
	        (BLOCK_H + BLOCK_BORDER_H) * i +
	        BLOCK_H * (2 - block_h) / 2;

	      draw.h = BLOCK_H;
	      draw.w = BLOCK_W;
            	
	      SDL_FillRect(screen, &draw, level_colors[level][tetrad]);

	      /* Top Border */
	      if(0 == i || tetrad != (next_grid[j][i - 1] - 1) / TETRAD_TILE_TYPE_COUNT || empty_tile == next_grid[j][i - 1])
		      for(k = 0 - BLOCK_BORDER_W; k < BLOCK_W + BLOCK_BORDER_W; k++)
 			      SetPixel2(draw.x + k, draw.y - BLOCK_BORDER_H, 0xFFFFFF);
	      else
		      for(k = 0; k < BLOCK_W; k++)
 			      SetPixel2(draw.x + k, draw.y - BLOCK_BORDER_H, level_colors[level][tetrad]);

	      /* Bottom Border */
	      if((PIPE_H - 1) == i || empty_tile == next_grid[j][i + 1])
		      for(k = 0 - BLOCK_BORDER_W; k < BLOCK_W + BLOCK_BORDER_W; k++)
			      SetPixel2(draw.x + k , draw.y + BLOCK_BORDER_H + BLOCK_H - 1, 0xFFFFFF);
	      else
		      for(k = 0; k < BLOCK_W; k++)
 			      SetPixel2(draw.x + k, draw.y + BLOCK_BORDER_H + BLOCK_H - 1, level_colors[level][tetrad]);

	      /* Left Border */
	      if(0 == j || tetrad != (next_grid[j - 1][i] - 1) / TETRAD_TILE_TYPE_COUNT || empty_tile == next_grid[j - 1][i])
		      for(k = 0 - BLOCK_BORDER_H; k < BLOCK_H + BLOCK_BORDER_H; k++)
			      SetPixel2(draw.x - BLOCK_BORDER_W, draw.y + k, 0xFFFFFF);
	      else
		      for(k = 0; k < BLOCK_H; k++)
 			      SetPixel2(draw.x - BLOCK_BORDER_W, draw.y + k, level_colors[level][tetrad]);

	      /* Right Border */
	      if((PIPE_W - 1) == j || empty_tile == next_grid[j + 1][i])
		      for(k = 0 - BLOCK_BORDER_H; k < BLOCK_H + BLOCK_BORDER_H; k++)
			      SetPixel2(draw.x + BLOCK_BORDER_W + BLOCK_W - 1, draw.y + k, 0xFFFFFF);
	      else
		      for(k = 0; k < BLOCK_H; k++)
 			      SetPixel2(draw.x + BLOCK_BORDER_W + BLOCK_W - 1, draw.y + k, level_colors[level][tetrad]);

	      /* Corners (only handles top left corner, but that's all we need, since it is a communal corner) */
	      if((!(0 == i || tetrad != (next_grid[j][i - 1] - 1) / TETRAD_TILE_TYPE_COUNT || empty_tile == next_grid[j][i - 1]))
		      && (!(0 == j || tetrad != (next_grid[j - 1][i] - 1) / TETRAD_TILE_TYPE_COUNT || empty_tile == next_grid[j - 1][i]))
		      && (!((0 == i && j == 0) || tetrad != (next_grid[j - 1][i - 1] - 1) / TETRAD_TILE_TYPE_COUNT || empty_tile == next_grid[j - 1][i - 1])))
		      SetPixel2(draw.x - BLOCK_BORDER_W, draw.y - BLOCK_BORDER_H, level_colors[level][tetrad]);

      }
    }
  }

  sprintf(level_chr, "%d", level); 
  sprintf(lines_chr, "%d", lines_cleared); 
  sprintf(score_chr, "%d", score); 
  level_text = TTF_RenderText_Solid(font, level_chr, textColor);
  lines_text = TTF_RenderText_Solid(font, lines_chr, textColor);
  score_text = TTF_RenderText_Solid(font, score_chr, textColor);

  type.x = TEXT_X + score_w + TEXT_X_SEP;
  type.y = TEXT_Y;
  SDL_BlitSurface(level_text, NULL, screen, &type);
  type.y = TEXT_Y + font_h + TEXT_Y_SEP;
  SDL_BlitSurface(lines_text, NULL, screen, &type);
  type.y = TEXT_Y + 2 * (font_h + TEXT_Y_SEP);
  SDL_BlitSurface(score_text, NULL, screen, &type);

  SDL_FreeSurface(level_text);
  SDL_FreeSurface(lines_text);
  SDL_FreeSurface(score_text);

  SDL_Flip(screen);
}

void TerminateDisplay() {
  SDL_FreeSurface(screen);
  TTF_CloseFont(font);
  TTF_Quit();
  SDL_Quit();
}

void NukeLines() {
	SDL_Rect draw;
	int i;
	int nuke_lines = 0;

	struct timespec *sleep_time, *return_time;
	sleep_time = malloc(sizeof(struct timespec*));
	sleep_time->tv_sec = 0;
	sleep_time->tv_nsec = 250000000;

	for(i = 0; i < PIPE_H; i++) {
		if(IsLineFull(i)) {
			draw.x = SCREEN_LEFT_EDGE + PIPE_EDGE_W;
			draw.y = SCREEN_TOP_EDGE + PIPE_EDGE_H + BLOCK_H * i + BLOCK_BORDER_H * (i - 1);
			draw.h = BLOCK_H + 2 * BLOCK_BORDER_H;
			draw.w = P_WDT;

			SDL_FillRect(screen, &draw, 0xFFFFFF);
			nuke_lines = 1;
		}
	}
	SDL_Flip(screen);
	if(nuke_lines)
	  nanosleep(sleep_time, return_time);
}

void PauseDisplay() {
	SDL_Rect draw, type;
	int pause_w;
  SDL_Surface* paused_text;
  draw.x = SCREEN_LEFT_EDGE + PIPE_EDGE_W;
  draw.y = SCREEN_TOP_EDGE + PIPE_EDGE_H;
  draw.h = P_HGT;
  draw.w = P_WDT;

  TTF_SizeText(font, "Paused", &pause_w, &font_h);

  /* Clear view */
  SDL_FillRect(screen, &draw, 0x000000);

  paused_text = TTF_RenderText_Solid(font, "Paused", textColor);

  type.x = SCREEN_LEFT_EDGE + PIPE_EDGE_W + (P_WDT - pause_w) / 2;
  type.y = SCREEN_TOP_EDGE + PIPE_EDGE_H + (P_HGT - font_h) / 2;
  SDL_BlitSurface(paused_text, NULL, screen, &type);

  SDL_FreeSurface(paused_text);

  SDL_Flip(screen);
}
