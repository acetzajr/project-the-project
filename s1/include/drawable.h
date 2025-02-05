#pragma once

#include <SDL3/SDL.h>

#include "sprite.h"

typedef struct
{
  sprite_t sprite, SDL_FRect srcrect;
  SDL_FRect dstrect;
  double angle;
  SDL_FPoint center, SDL_FlipMode flip
}