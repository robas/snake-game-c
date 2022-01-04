#ifndef BOARD_H
#define BOARD_H

#include <ncurses.h>

#include "snake.h"

int max_x, max_y;

WINDOW *initializeBoard();
void destroyBoard();
void drawBoard(WINDOW *window, Snake snk);
int getNewDirection(Snake snk, int direction);
void processMovement(Snake *snk);
bool isThereCollision(WINDOW *win, Snake snk);

#endif