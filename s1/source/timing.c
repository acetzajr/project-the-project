#include "timing.h"

#include "state.h"

bool
timing ()
{
  state.timing.current = SDL_GetTicks ();
  state.timing.delta = state.timing.current - state.timing.past;
  state.timing.past = state.timing.current;
  if (state.timing.counter % 16 == 0)
    {
      state.timing.fps = 1'000.0 / state.timing.delta;
    }
  state.timing.counter = (state.timing.counter + 1) % 16;
  return true;
}