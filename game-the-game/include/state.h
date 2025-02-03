#pragma once

#include "gamepad.h"
#include "space.h"
#include "timing.h"
#include "sdl.h"

typedef struct
{
    space_t space;
    sdl_t sdl;
    gamepad_t gamepads[MAX_GAMEPADS];
    timing_t timing;
    bool running;
} state_t;

extern state_t state;

