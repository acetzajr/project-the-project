#include "init.h"

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "error.h"
#include "space.h"
#include "state.h"

void
cleanup_surface (SDL_Surface **surface)
{
  if (*surface)
    {
      SDL_DestroySurface (*surface);
      *surface = nullptr;
    }
}

bool
load_sprite (sprite_t *sprite)
{
  [[gnu::cleanup (cleanup_surface)]]
  SDL_Surface *surface
      = SDL_LoadBMP (sprite->path);
  if (!surface)
    {
      return sdl_error ("!surface");
    }
  sprite->texture = SDL_CreateTextureFromSurface (state.sdl.renderer, surface);
  if (!sprite->texture)
    {
      return sdl_error ("!sprite->texture");
    }
  sprite->width = sprite->texture->w;
  sprite->height = sprite->texture->h;
  return true;
}

bool
load_sprites ()
{
  for (int i = 0; i < SPRITE_COUNT; ++i)
    {
      if (!load_sprite (&state.sprites[i]))
        {
          return error ("load_sprite");
        }
    }
  return true;
}

bool
init ()
{
  printf ("%s\n", SDL_GetRevision ());
  if (!SDL_SetHint (SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1"))
    {
      return sdl_error ("SDL_SetHint");
    }
  state.sdl.init = SDL_Init (SDL_INIT_VIDEO | SDL_INIT_GAMEPAD);
  if (!state.sdl.init)
    {
      return sdl_error ("SDL_Init");
    }
  state.sdl.window
      = SDL_CreateWindow ("Game The Game", 1024, 512, SDL_WINDOW_HIDDEN);
  if (!state.sdl.window)
    {
      return sdl_error ("SDL_CreateWindow");
    }
  state.sdl.renderer = SDL_CreateRenderer (state.sdl.window, nullptr);
  if (!state.sdl.renderer)
    {
      return sdl_error ("SDL_CreateRenderer");
    }
  if (!SDL_SetRenderVSync (state.sdl.renderer, 1))
    {
      return sdl_error ("SDL_SetRenderVSync");
    }
  state.sdl.viewport
      = SDL_CreateTexture (state.sdl.renderer, SDL_PIXELFORMAT_UNKNOWN,
                           SDL_TEXTUREACCESS_TARGET, 256, 128);
  if (!state.sdl.viewport)
    {
      return sdl_error ("SDL_CreateTexture");
    }
  if (!SDL_SetTextureScaleMode (state.sdl.viewport, SDL_SCALEMODE_NEAREST))
    {
      return sdl_error ("SDL_SetTextureScaleMode");
    }
  if (!load_sprites ())
    {
      return error ("load_sprites");
    }
  state.space.width = 256;
  state.space.height = 128;
  state.space.cells
      = malloc (sizeof (cell_t) * state.space.width * state.space.height);
  if (!state.space.cells)
    {
      return error ("!state.space.cells");
    }
  state.timing.past = SDL_GetTicks ();
  state.running = true;
  if (!SDL_ShowWindow (state.sdl.window))
    {
      return sdl_error ("SDL_ShowWindow");
    }
  return true;
}