#pragma once

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
    int width;
    int height;
    cell_t *cells;
} space_t;