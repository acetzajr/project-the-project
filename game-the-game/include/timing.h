#pragma once

#include <SDL3/SDL.h>

typedef struct
{
    Uint64 past, delta, current;
    float fps;
    int counter;
} timing_t;

bool timing();