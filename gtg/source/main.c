#include "sdl.h"
#include "std.h"

typedef struct {
  bool sdl_error;
  sdl_window_t *window;
} gtg_globals_t;

gtg_globals_t gtg_globals = {
    .sdl_error = false,
    .window = nullptr,
};

[[gnu::destructor]]
void gtg_cleanup() {
  sdl_log("Cleaning up ...\n");
  sdl_quit();
}

bool gtg_sdl_error(const char *fmt, ...) {
  va_list_t args;
  va_start(args);
  sdl_log(fmt, args);
  va_end(args);
  gtg_globals.sdl_error = true;
  return false;
}

bool gtg_init() {
  if (!sdl_init(SDL_INIT_VIDEO)) {
    return false;
  }
  gtg_globals.window = sdl_create_window("gtg", 1024, 720, SDL_WINDOW_HIDDEN);
  if (!gtg_globals.window) {
    return false;
  }
  return true;
}

int main() {
  sdl_log("Hello platformer\n");
  if (!gtg_init()) {
    return 1;
  }
  return 0;
}