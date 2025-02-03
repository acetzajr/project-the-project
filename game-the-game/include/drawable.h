#pragma once

#include <SDL3/SDL.h>

typedef struct
{
    SDL_Texture *texture,
    SDL_FRect srcrect;
    SDL_FRect dstrect;
    double angle;
    SDL_FPoint center,
    SDL_FlipMode flip
}