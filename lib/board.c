#include "board.h"

#include <stdio.h>

#include "coordinates.h"

void configureEmptyBoard() {
    for (int i = 0; i < boardWidth; i++) {
        for (int j = 0; j < boardHeight; j++) {
            board[i][j] = ' ';
        }
    }
    for (int i = 0; i < boardHeight; i++) {
        board[0][i] = '#';
        board[boardWidth - 1][i] = '#';
    }
    for (int i = 0; i < boardWidth; i++) {
        board[i][0] = '#';
        board[i][boardHeight - 1] = '#';
    }
}

void resetScreen() {
    for (int i = 0; i < 5; i++) {
        printf("\n");
    }
}

void drawBoard() {
    resetScreen();
    for (int j = 0; j < boardHeight; j++) {
        for (int i = 0; i < boardWidth; i++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void pinOnBoard(Coordinates pos, char symbol) {
    board[pos.x][pos.y] = symbol;
}

Coordinates getNewPosition(Coordinates actualPos, Coordinates movement) {
    Coordinates newPos;
    int newX = actualPos.x + movement.x;
    int newY = actualPos.y + movement.y;

    if (newX > 0 && newX < boardWidth - 1) {
        newPos.x = newX;
    } else {
        if (newX == 0) newPos.x = boardWidth - 2;
        if (newX == boardWidth - 1) newPos.x = 1;
    }

    if (newY > 0 && newY < boardHeight - 1) {
        newPos.y = newY;
    } else {
        if (newY == 0) newPos.y = boardHeight - 2;
        if (newY == boardHeight - 1) newPos.y = 1;
    }

    return newPos;
}

Coordinates movePlayer(Coordinates actualPos, Coordinates movement) {
    pinOnBoard(actualPos, ' ');
    actualPos = getNewPosition(actualPos, movement);

    pinOnBoard(actualPos, 'x');
    return actualPos;
}