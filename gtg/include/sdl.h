#pragma once

#include <SDL3/SDL.h>

typedef SDL_InitFlags sdl_init_flags_t;
typedef SDL_WindowFlags sdl_window_flags_t;
typedef SDL_Window sdl_window_t;

void sdl_log (const char *fmt, ...);

bool sdl_init (sdl_init_flags_t flags);

void sdl_quit ();

sdl_window_t *sdl_create_window (const char *title, int w, int h,
                                 sdl_window_flags_t flags);

void sdl_destroy_window (sdl_window_t *window);