#include "draw.h"
#include "state.h"
#include <SDL3/SDL.h>

bool draw()
{
    SDL_SetRenderDrawColorFloat(state.sdl.renderer, 0, 0, 0, 1);
    SDL_RenderClear(state.sdl.renderer);
    SDL_SetRenderDrawColorFloat(state.sdl.renderer, 1, 1, 1, 1);
    SDL_RenderDebugTextFormat(state.sdl.renderer, 0, 0, "fps %.3f", state.timing.fps);
    SDL_RenderPresent(state.sdl.renderer);
    return true;
}