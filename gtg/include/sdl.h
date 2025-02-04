#pragma once
#include <SDL3/SDL.h>
typedef SDL_InitFlags sdl_init_flags_t;
void sdl_log(const char *fmt, ...);
bool sdl_init(sdl_init_flags_t flags);
void sdl_quit();