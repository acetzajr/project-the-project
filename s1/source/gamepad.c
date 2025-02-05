#include "gamepad.h"

#include <SDL3/SDL.h>
#include <stdio.h>

#include "state.h"

bool
add_gamepad (SDL_JoystickID id)
{
  int player = SDL_GetGamepadPlayerIndexForID (id);
  if (player < 0 || player >= 4)
    {
      return false;
    }
  state.gamepads[player].id = id;
  state.gamepads[player].sdl = SDL_OpenGamepad (id);
  if (state.gamepads[player].sdl)
    {
      state.gamepads[player].connected = true;
      printf ("player %d connected\n", player);
      return true;
    }
  state.gamepads[player].connected = false;
  return false;
}

void
remove_gamepad (SDL_JoystickID id)
{
  for (int player = 0; player < MAX_GAMEPADS; ++player)
    {
      if (state.gamepads[player].id == id)
        {
          SDL_CloseGamepad (state.gamepads[player].sdl);
          printf ("player %d disconnected\n", player);
        }
    }
}