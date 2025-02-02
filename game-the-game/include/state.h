#pragma once

#include "gamepad.h"

typedef struct
{
    Uint64 past, delta, current;
    float fps;
    int counter;
} timing_t;

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool error;
    bool init;
} sdl_t;

typedef struct
{
    sdl_t sdl;
    bool running;
    gamepad_t gamepads[MAX_GAMEPADS];
    timing_t timing;
} state_t;

extern state_t state;

