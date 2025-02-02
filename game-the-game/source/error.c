#include "error.h"
#include "state.h"

bool sdl_error()
{
    state.sdl.error = true;
    return false;
}