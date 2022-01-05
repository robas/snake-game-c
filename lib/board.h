#ifndef BOARD_H
#define BOARD_H

#include <ncurses.h>

#include "coordinates.h"
#include "objects.h"

int max_x, max_y;

WINDOW *initializeBoard();
void destroyBoard();
void drawBoard(WINDOW *win, Snake snk, Apple a);
int getNewDirection(Snake snk, int direction);
void processMovement(Snake *snk, Apple *a);
Coordinates getRandomPositionOtherThan(WINDOW *w, Coordinates pos[], int len);
bool isThereWallCollision(WINDOW *win, Snake snk);
bool isThereCollision(Coordinates c, Coordinates pos[], int len);

#endif