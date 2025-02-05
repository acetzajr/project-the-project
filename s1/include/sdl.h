#pragma once

typedef struct
{
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Texture *viewport;
  bool error;
  bool init;
} sdl_t;