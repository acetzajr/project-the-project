#include "sdl.h"
#include <SDL3/SDL.h>
#include <stdarg.h>
inline void sdl_log(const char *fmt, ...)
{
    va_list args;
    va_start(args);
    SDL_Log(fmt, args);
    va_end(args);
}
inline bool sdl_init(sdl_init_flags_t flags)
{
    return SDL_Init(flags);
}
inline void sdl_quit()
{
    SDL_Quit();
}