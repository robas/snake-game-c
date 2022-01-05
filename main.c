#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "board.h"
#include "objects.h"

#define initialXPos 1
#define initialYPos 1
#define INITIAL_DELAY 200000
#define SPEEDUP_GAME gameSpeed -= gameSpeed > 10000 ? 10000 : 0
Snake snake;
Apple apple;
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
        case 'w':
            SPEEDUP_GAME;
            break;
        case 'q':
            runGame = FALSE;
        default:
            break;
    }
}

int main() {
    WINDOW *field = initializeBoard();
    snake = initializeSnake(initialXPos, initialYPos);
    apple = initializeApple(field, snake);

    drawBoard(field, snake, apple);

    while (runGame == TRUE) {
        handleCmd();
        processMovement(&snake, &apple);
        if (apple.eaten) {
            apple = initializeApple(field, snake);
            SPEEDUP_GAME;
        }
        drawBoard(field, snake, apple);
        if (isThereWallCollision(field, snake)) {
            runGame = FALSE;
        }
        usleep(gameSpeed);
    }
    destroyBoard();
}