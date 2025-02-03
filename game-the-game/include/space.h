#pragma once

#define MAX_SPACE_WIDTH 256
#define MAX_SPACE_HEIGHT 128

typedef enum
{
    OCCUPANT_NONE,
    OCCUPANT_STATIC_BLOCK,
} occupant_type_t;

typedef struct
{
    occupant_type_t type;
    void *occupant;
} cell_t;

typedef struct
{
    cell_t cells[MAX_SPACE_WIDTH][MAX_SPACE_HEIGHT];
} space_t;