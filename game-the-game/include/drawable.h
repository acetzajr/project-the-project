#pragma once

#include "sprite.h"
#include <SDL3/SDL.h>

typedef struct
{
    sprite_t sprite,
    SDL_FRect srcrect;
    SDL_FRect dstrect;
    double angle;
    SDL_FPoint center,
    SDL_FlipMode flip
}