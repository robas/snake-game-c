#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "board.h"
// #include "coordinates.h"
#include "snake.h"

#define initialXPos 0
#define initialYPos 0
#define INITIAL_DELAY 250000

Snake snake = {{initialXPos, initialYPos}, RIGHT_DIR};
bool runGame = TRUE;
int gameSpeed = INITIAL_DELAY;

void handleCmd() {
    int cmd = getch();
    switch (cmd) {
        case KEY_UP:
            snake.direction = getNewDirection(snake, UP_DIR);
            break;
        case KEY_LEFT:
            snake.direction = getNewDirection(snake, LEFT_DIR);
            break;
        case KEY_DOWN:
            snake.direction = getNewDirection(snake, DOWN_DIR);
            break;
        case KEY_RIGHT:
            snake.direction = getNewDirection(snake, RIGHT_DIR);
            break;
        case 'q':
            runGame = FALSE;
        default:
            break;
    }
}

int main() {
    initializeBoard();
    drawBoard(snake);

    while (runGame == TRUE) {
        handleCmd();
        processMovement(&snake);
        drawBoard(snake);
        if (isThereCollision(snake)) {
            runGame = FALSE;
        }
        usleep(gameSpeed);
    }
    destroyBoard();
}