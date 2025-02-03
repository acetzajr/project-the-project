#include "state.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>

[[gnu::destructor]]
void cleanup()
{
    if(state.space.cells)
    {
        free(state.space.cells);
    }
    if(state.sdl.renderer)
    {
        SDL_DestroyRenderer(state.sdl.renderer);
    }
    if(state.sdl.window)
    {
        SDL_DestroyWindow(state.sdl.window);
    }
    if(state.sdl.error)
    {
        fprintf(stderr, "%s\n", SDL_GetError());
    }
    if(state.sdl.init)
    {
        for(int player = 0; player < MAX_GAMEPADS; ++player)
        {
            if(state.gamepads[player].connected)
            {
                SDL_CloseGamepad(state.gamepads[player].sdl);
            }
        }
        SDL_Quit();
    }
}