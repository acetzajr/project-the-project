#include "state.h"

#include "gamepad.h"
#include "space.h"

const cell_t null_cell = {
  .type = OCCUPANT_NONE,
  .occupant = nullptr,
};

const gamepad_t null_gamepad = {
  .sdl = nullptr,
  .id = -1,
  .connected = false,
};

state_t state = {
    .mode = MODE_SPACE_EDITOR,
    .sprites =
        {
            {.name = SPRITE_SKY,
             .path = "resources/game-the-game/sprites/sprite-sky.bmp"},
            {.name = SPRITE_BLOCK,
             .path = "resources/game-the-game/sprites/sprite-block.bmp"},
            {.name = SPRITE_PLAYER,
             .path = "resources/game-the-game/sprites/sprite-player.bmp"},
        },
    .space = {.cells = nullptr},
    .sdl =
        {
            .viewport = nullptr,
            .window = nullptr,
            .renderer = nullptr,
            .error = false,
            .init = false,
        },
    .running = true,
    .gamepads = {null_gamepad},
    .timing =
        {
            .delta = 16,
            .fps = 1'000.0 / 16.0,
            .counter = 0,
        },

};
