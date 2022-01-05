#ifndef SNAKE_H
#define SNAKE_H

#include <ncurses.h>

#include "coordinates.h"

#define RIGHT_DIR 1
#define LEFT_DIR -1
#define UP_DIR 2
#define DOWN_DIR -2

typedef struct str_snake {
    Coordinates pos[256];
    int size;
    int direction;
} Snake;

typedef struct str_apple {
    Coordinates pos;
    bool eaten;
} Apple;

Snake initializeSnake(int x, int y);
Apple initializeApple(WINDOW *field, Snake snk);

#endif