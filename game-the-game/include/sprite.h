#pragma once

#include <SDL3/SDL.h>

typedef enum {
  SPRITE_SKY = 0,
  SPRITE_BLOCK,
  SPRITE_PLAYER,
  SPRITE_COUNT,
} sprite_name_t;

typedef struct {
  sprite_name_t name;
  const char *path;
  SDL_Texture *texture;
  int width, height;
} sprite_t;