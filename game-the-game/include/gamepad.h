#pragma once

#include <SDL3/SDL.h>

#define MAX_GAMEPADS 4

typedef struct {
  SDL_Gamepad *sdl;
  SDL_JoystickID id;
  bool connected;
} gamepad_t;

bool add_gamepad(SDL_JoystickID id);

void remove_gamepad(SDL_JoystickID id);