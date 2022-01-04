#ifndef BOARD_H
#define BOARD_H

#include <ncurses.h>

#include "snake.h"

int max_x, max_y;

void initializeBoard();
void destroyBoard();
void drawBoard();
int getNewDirection(Snake snk, int direction);
void processMovement(Snake *snk);
bool isThereCollision(Snake snk);

#endif