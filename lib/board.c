#include "board.h"

#include <stdio.h>

#include "snake.h"

void initializeBoard() {
    initscr();
    noecho();
    curs_set(FALSE);
    raw();
    keypad(stdscr, TRUE);
    timeout(10);
    getmaxyx(stdscr, max_y, max_x);
}

void destroyBoard() {
    endwin();
}

void drawBoard(Snake snk) {
    getmaxyx(stdscr, max_y, max_x);
    clear();
    mvprintw(snk.pos.x, snk.pos.y, "O");
    refresh();
}

bool isOpositeDirection(int dir1, int dir2) {
    if (dir1 + dir2 == 0) {
        return TRUE;
    }
    return FALSE;
}

int getNewDirection(Snake snk, int direction) {
    if (isOpositeDirection(snk.direction, direction)) {
        return snk.direction;
    } else {
        return direction;
    }
}
bool isThereCollision(Snake snk) {
    if (snk.pos.x > max_x || snk.pos.x < 0 || snk.pos.y > max_y || snk.pos.y < 0) {
        return TRUE;
    }
    return FALSE;
}

void processMovement(Snake *snk) {
    switch (snk->direction) {
        case UP_DIR:
            snk->pos.x--;
            break;
        case DOWN_DIR:
            snk->pos.x++;
            break;
        case LEFT_DIR:
            snk->pos.y--;
            break;
        case RIGHT_DIR:
            snk->pos.y++;
            break;
    }
}