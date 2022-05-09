#include "SDL.h"
#include "SDL_render.h"
#include "SDL_video.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  const int SCREEN_WIDTH = 640;
  const int SCREEN_HEIGTH = 420;

  SDL_Window *windown = NULL;
  SDL_Renderer *renderer = NULL;
  SDL_Texture *bitmapTex = NULL;
  SDL_bool loopShouldStop = SDL_FALSE;

  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s",
                 SDL_GetError());
  }

  windown =
      SDL_CreateWindow("Bouncy Circles", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGTH, 0);

  renderer = SDL_CreateRenderer(windown, -1, SDL_RENDERER_ACCELERATED);

  while (!loopShouldStop) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        loopShouldStop = SDL_TRUE;
        break;
      }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
    SDL_RenderPresent(renderer);
  }

  SDL_DestroyTexture(bitmapTex);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(windown);

  SDL_Quit();

  return (EXIT_SUCCESS);
}
