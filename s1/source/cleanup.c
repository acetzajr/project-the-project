#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "sprite.h"
#include "state.h"

[[gnu::destructor]]
void
cleanup ()
{
  if (state.sdl.error)
    {
      fprintf (stderr, "%s\n", SDL_GetError ());
    }
  if (state.space.cells)
    {
      free (state.space.cells);
    }
  if (state.sdl.viewport)
    {
      SDL_DestroyTexture (state.sdl.viewport);
    }
  if (state.sdl.renderer)
    {
      SDL_DestroyRenderer (state.sdl.renderer);
    }
  if (state.sdl.window)
    {
      SDL_DestroyWindow (state.sdl.window);
    }
  for (int i = 0; i < SPRITE_COUNT; ++i)
    {
      if (state.sprites[i].texture)
        {
          SDL_DestroyTexture (state.sprites[i].texture);
        }
    }
  if (state.sdl.init)
    {
      for (int player = 0; player < MAX_GAMEPADS; ++player)
        {
          if (state.gamepads[player].connected)
            {
              SDL_CloseGamepad (state.gamepads[player].sdl);
            }
        }
      SDL_Quit ();
    }
}