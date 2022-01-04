#ifndef SNAKE_H
#define SNAKE_H

#include "coordinates.h"

#define RIGHT_DIR 1
#define LEFT_DIR -1
#define UP_DIR 2
#define DOWN_DIR -2

typedef struct str_snake {
    Coordinates pos;
    int direction;
} Snake;

#endif