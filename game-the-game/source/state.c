#include "state.h"
#include "gamepad.h"
#include "space.h"

const cell_t null_cell =
{
    .type = OCCUPANT_NONE,
    .occupant = nullptr,
};

const gamepad_t null_gamepad = 
{
    .sdl = nullptr,
    .id = -1,
    .connected = false,
};

state_t state = 
{
    .space = { .cells = nullptr },
    .sdl =
    {
        .window = nullptr,
        .renderer = nullptr,
        .error = false,
        .init = false,
    },
    .running = true,
    .gamepads = { null_gamepad },
    .timing = 
    {
        .delta = 16,
        .fps = 1'000.0 / 16.0,
        .counter = 0,
    },

};
