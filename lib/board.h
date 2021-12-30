#ifndef BOARD_H
#define BOARD_H

#define boardWidth 12
#define boardHeight 12

#include "coordinates.h"

char board[boardWidth][boardHeight];

void configureEmptyBoard();
void drawBoard();
void pinOnBoard(Coordinates pos, char symbol);
Coordinates getNewPosition(Coordinates actualPos, Coordinates movement);
Coordinates movePlayer(Coordinates actualPos, Coordinates movement);

#endif