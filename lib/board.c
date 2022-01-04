#include "board.h"

#include <stdio.h>

#include "snake.h"

WINDOW *initializeBoard() {
    initscr();
    noecho();
    curs_set(FALSE);
    raw();
    keypad(stdscr, TRUE);
    timeout(10);
    getmaxyx(stdscr, max_y, max_x);

    WINDOW *field = newwin(max_y, max_x, 0, 0);
    return field;
}

void draw_borders(WINDOW *screen) {
    // 4 corners
    mvwprintw(screen, 0, 0, "+");
    mvwprintw(screen, max_y - 1, 0, "+");
    mvwprintw(screen, 0, max_x - 1, "+");
    mvwprintw(screen, max_y - 1, max_x - 1, "+");

    // sides
    for (int i = 1; i < (max_y - 1); i++) {
        mvwprintw(screen, i, 0, "|");
        mvwprintw(screen, i, max_x - 1, "|");
    }

    // top and bottom
    for (int i = 1; i < (max_x - 1); i++) {
        mvwprintw(screen, 0, i, "-");
        mvwprintw(screen, max_y - 1, i, "-");
    }
}

void destroyBoard() {
    endwin();
}

void drawBoard(WINDOW *win, Snake snk) {
    getmaxyx(win, max_y, max_x);
    wclear(win);
    draw_borders(win);
    mvwprintw(win, snk.pos.y, snk.pos.x, "O");
    wrefresh(win);
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
bool isThereCollision(WINDOW *win, Snake snk) {
    getmaxyx(win, max_y, max_x);
    if (snk.pos.x >= max_x || snk.pos.x <= 0 || snk.pos.y >= max_y - 1 || snk.pos.y <= 0) {
        return TRUE;
    }
    return FALSE;
}

void processMovement(Snake *snk) {
    switch (snk->direction) {
        case UP_DIR:
            snk->pos.y--;
            break;
        case DOWN_DIR:
            snk->pos.y++;
            break;
        case LEFT_DIR:
            snk->pos.x--;
            break;
        case RIGHT_DIR:
            snk->pos.x++;
            break;
    }
}