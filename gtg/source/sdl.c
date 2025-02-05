#include "sdl.h"

#include <SDL3/SDL.h>

#include "std.h"

void sdl_log(const char *fmt, ...) {
  va_list_t args;
  va_start(args);
  SDL_Log(fmt, args);
  va_end(args);
}

bool sdl_init(sdl_init_flags_t flags) { return SDL_Init(flags); }

void sdl_quit() { SDL_Quit(); }

sdl_window_t *sdl_create_window(const char *title, int w, int h,
                                sdl_window_flags_t flags) {
  return SDL_CreateWindow(title, w, h, flags);
}

void sdl_destroy_window(sdl_window_t *window) { SDL_DestroyWindow(window); }