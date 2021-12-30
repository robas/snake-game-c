#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "board.h"
#include "coordinates.h"

#define initialXPos 1
#define initialYPos 1

Coordinates playerPos = {initialXPos, initialYPos};
int cmd;

int handleCmd() {
    cmd = getchar();
    switch (cmd) {
        case 'w':
            playerPos = movePlayer(playerPos, UP);
            break;
        case 'a':
            playerPos = movePlayer(playerPos, LEFT);
            break;
        case 's':
            playerPos = movePlayer(playerPos, DOWN);
            break;
        case 'd':
            playerPos = movePlayer(playerPos, RIGHT);
            break;
        default:
            break;
    }
    return cmd;
}

int main() {
    configureEmptyBoard();
    pinOnBoard(playerPos, 'x');

    cmd = 0;

    while (cmd != 27) {
        drawBoard();
        handleCmd();
    }
}