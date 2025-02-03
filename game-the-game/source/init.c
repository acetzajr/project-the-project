#include "init.h"
#include "state.h"
#include "error.h"
#include "space.h"
#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>

bool init()
{
    printf("%s\n", SDL_GetRevision());
    if(!SDL_SetHint(SDL_HINT_JOYSTICK_ALLOW_BACKGROUND_EVENTS, "1"))
    {
        return sdl_error();
    }
    state.sdl.init = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD);
    if(!state.sdl.init)
    {
        return sdl_error();
    }
    state.sdl.window = SDL_CreateWindow("Game The Game", 1024, 512, SDL_WINDOW_HIDDEN);
    if(!state.sdl.window)
    {
        return sdl_error();
    }
    state.sdl.renderer = SDL_CreateRenderer(state.sdl.window, nullptr);
    if(!state.sdl.renderer)
    {
        return sdl_error();
    }
    if(!SDL_SetRenderVSync(state.sdl.renderer, 1))
    {
        return sdl_error();
    }
    if(!SDL_ShowWindow(state.sdl.window))
    {
        return sdl_error();
    }
    state.space.width = 256;
    state.space.height = 128;
    state.space.cells =
        malloc(sizeof(cell_t) * state.space.width * state.space.height);
    if(!state.space.cells)
    {
        fprintf(stderr, "!state.space.cells\n");
        return false;
    }
    state.timing.past = SDL_GetTicks();
    state.running = true;
    return true;
}