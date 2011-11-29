#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#define S_WDT 640
#define S_HGT 480
#define S_BPP 32

SDL_Surface* message = NULL;
SDL_Surface* background = NULL;
SDL_Surface* screen = NULL;

SDL_Event event;

SDL_Surface* LoadImage(char* file_name) {
  SDL_Surface* loaded_image = NULL;
  SDL_Surface* optimized_image = NULL;
  if(loaded_image = IMG_Load(file_name)) {
    if(optimized_image = SDL_DisplayFormat(loaded_image)) {
      Uint32 colorkey = SDL_MapRGB(optimized_image->format, 0xFF, 0xFF, 0xFF);
      SDL_SetColorKey
	(optimized_image, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey);
    }
    SDL_FreeSurface(loaded_image);
  } else printf("Failure!\n");
  return optimized_image;
}

void ApplySurface(int x, int y, SDL_Surface* source, SDL_Surface* destination)
{
  SDL_Rect offset;
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(source, NULL, destination, &offset);
}

int main() {
  if(
     -1 == SDL_Init(SDL_INIT_VIDEO) || 
     NULL == (screen = SDL_SetVideoMode(S_WDT, S_HGT, S_BPP, SDL_SWSURFACE)))
    return 1; 

  SDL_WM_SetCaption("Hello World", NULL);

  message = LoadImage("hello_world.png");
  background = LoadImage("redback.png");

  ApplySurface(0, 0, background, screen);
  ApplySurface(180, 140, message, screen);

  if(SDL_Flip(screen) == -1) return 1;

  int quit = 0;
  while(!quit) {
    while(SDL_PollEvent(&event)) {
      if(event.type == SDL_QUIT) quit = 0;
    }
  }

  SDL_FreeSurface(message);
  SDL_FreeSurface(background);

  SDL_Quit();
  return 0;
}
