#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "board.h"
// #include "coordinates.h"
#include "snake.h"

#define initialXPos 1
#define initialYPos 1
#define INITIAL_DELAY 200000

Snake snake;
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
    WINDOW *field = initializeBoard();
    drawBoard(field, snake);
    snake.size = 3;
    snake.direction = RIGHT_DIR;
    snake.pos[0].x = initialXPos + 2;
    snake.pos[0].y = initialYPos;
    snake.pos[1].x = initialXPos + 1;
    snake.pos[1].y = initialYPos;
    snake.pos[2].x = initialXPos;
    snake.pos[3].y = initialYPos;

    while (runGame == TRUE) {
        handleCmd();
        processMovement(&snake);
        drawBoard(field, snake);
        if (isThereCollision(field, snake)) {
            runGame = FALSE;
        }
        usleep(gameSpeed);
    }
    destroyBoard();
}