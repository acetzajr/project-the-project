#include "draw.h"

#include <SDL3/SDL.h>

#include "error.h"
#include "sprite.h"
#include "state.h"

bool
draw_sky ()
{
  if (!SDL_RenderTextureTiled (state.sdl.renderer,
                               state.sprites[SPRITE_SKY].texture, nullptr, 1,
                               nullptr))
    {
      return sdl_error ("SDL_RenderTextureTiled");
    }
  return true;
}

bool
draw ()
{
  if (!SDL_SetRenderTarget (state.sdl.renderer, state.sdl.viewport))
    {
      return sdl_error ("SDL_SetRenderTarget");
    }
  if (!draw_sky ())
    {
      return error ("draw_sky");
    }
  if (!SDL_SetRenderTarget (state.sdl.renderer, nullptr))
    {
      return sdl_error ("SDL_SetRenderTarget");
    }
  SDL_SetRenderDrawColorFloat (state.sdl.renderer, 0, 0, 0, 1);
  SDL_RenderClear (state.sdl.renderer);
  if (!SDL_RenderTexture (state.sdl.renderer, state.sdl.viewport, nullptr,
                          nullptr))
    {
      return sdl_error ("SDL_RenderTexture");
    }
  SDL_SetRenderDrawColorFloat (state.sdl.renderer, 1, 1, 1, 1);
  if (!SDL_RenderDebugTextFormat (state.sdl.renderer, 0, 0, "fps %.3f",
                                  state.timing.fps))
    {
      return sdl_error ("SDL_RenderDebugTextFormat");
    }
  SDL_RenderPresent (state.sdl.renderer);
  return true;
}