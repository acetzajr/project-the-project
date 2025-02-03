#pragma once

#include "gamepad.h"
#include "space.h"
#include "timing.h"
#include "sdl.h"
#include "sprite.h"

typedef struct
{
    sprite_t sprites[SPRITE_COUNT];
    gamepad_t gamepads[MAX_GAMEPADS];
    sdl_t sdl;
    space_t space;
    timing_t timing;
    bool running;
} state_t;

extern state_t state;

