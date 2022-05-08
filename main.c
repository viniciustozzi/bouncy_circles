#include "SDL.h"
#include <SDL.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

  const int SCREEN_WIDTH = 640;
  const int SCREEN_HEIGTH = 320;

  SDL_Window *win = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Texture *bitmapTex = NULL;
  SDL_Surface *bitmapSurface = NULL;
  SDL_bool loopShouldStop = SDL_FALSE;

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    printf("Error on SDL_Init()");
  }

  win =
      SDL_CreateWindow("Hello World", 300, 300, SCREEN_WIDTH, SCREEN_HEIGTH, 0);

  renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

  bitmapSurface = SDL_LoadBMP("img/hello.bmp");
  bitmapTex = SDL_CreateTextureFromSurface(renderer, bitmapSurface);
  SDL_FreeSurface(bitmapSurface);

  while (!loopShouldStop) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        loopShouldStop = SDL_TRUE;
        break;
      }
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, bitmapTex, NULL, NULL);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(bitmapTex);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(win);

  SDL_Quit();

  return 0;
}
