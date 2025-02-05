#include "error.h"

#include <stdio.h>

#include "state.h"

bool
sdl_error (const char *message)
{
  fprintf (stderr, "SDL error: %s\n", message);
  state.sdl.error = true;
  return false;
}

bool
error (const char *message)
{
  fprintf (stderr, "Error: %s\n", message);
  return false;
}