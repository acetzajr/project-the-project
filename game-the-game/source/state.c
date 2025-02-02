#include "state.h"
#include "gamepad.h"

const gamepad_t null_gamepad = {nullptr, -1, false};

state_t state = 
{
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
