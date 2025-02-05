#pragma once

#include "gamepad.h"
#include "sdl.h"
#include "space.h"
#include "sprite.h"
#include "timing.h"

typedef enum
{
  MODE_SPACE_EDITOR,
} state_mode_t;

typedef struct
{
  state_mode_t mode;
  sprite_t sprites[SPRITE_COUNT];
  gamepad_t gamepads[MAX_GAMEPADS];
  sdl_t sdl;
  space_t space;
  timing_t timing;
  bool running;
} state_t;

extern state_t state;
