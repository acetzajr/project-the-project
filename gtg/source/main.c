#include "sdl.h"
[[gnu::destructor]]
void cleanup()
{
    sdl_log("Cleaning up ...\n");
    sdl_quit();
}
int main()
{
    sdl_log("Hello platformer\n");
    if(!sdl_init(SDL_INIT_VIDEO))
    {
        return 1;
    }
    return 0;
}