#pragma once

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool error;
    bool init;
} sdl_t;