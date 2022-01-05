#include "board.h"

#include <stdio.h>
#include <stdlib.h>

#include "objects.h"

WINDOW *initializeBoard() {
    initscr();
    noecho();
    curs_set(FALSE);
    raw();
    keypad(stdscr, TRUE);
    timeout(10);
    getmaxyx(stdscr, max_y, max_x);

    WINDOW *field = newwin(max_y, max_x, 0, 0);
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
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

void drawBoard(WINDOW *win, Snake snk, Apple a) {
    getmaxyx(win, max_y, max_x);
    wclear(win);
    draw_borders(win);
    for (int i = 0; i < snk.size; i++) {
        mvwprintw(win, snk.pos[i].y, snk.pos[i].x, "O");
    }
    wattron(win, COLOR_PAIR(1));
    mvwprintw(win, a.pos.y, a.pos.x, "*");
    wattroff(win, COLOR_PAIR(1));
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
bool isThereWallOrSelfCollision(WINDOW *win, Snake snk) {
    getmaxyx(win, max_y, max_x);
    if (snk.pos[0].x >= max_x - 1 || snk.pos[0].x <= 0 || snk.pos[0].y >= max_y - 1 || snk.pos[0].y <= 0) {
        return TRUE;
    }
    for (int i = 1; i < snk.size; i++) {
        if (snk.pos[0].x == snk.pos[i].x && snk.pos[0].y == snk.pos[i].y) {
            return TRUE;
        }
    }
    return FALSE;
}

Coordinates getRandomPositionOtherThan(WINDOW *w, Coordinates pos[], int len) {
    int high_x, high_y;
    Coordinates randomPos;
    getmaxyx(w, high_y, high_x);
    do {
        randomPos.x = 1 + (rand() % (high_x - 2));
        randomPos.y = 1 + (rand() % (high_y - 2));
    } while (isThereCollision(randomPos, pos, len));

    return randomPos;
}

bool isThereCollision(Coordinates c, Coordinates pos[], int len) {
    for (int i = 0; i < len; i++) {
        if (c.x == pos[i].x && c.y == pos[i].y) {
            return TRUE;
        }
    }
    return FALSE;
}

void processMovement(Snake *snk, Apple *a) {
    Coordinates snakeTail = snk->pos[snk->size - 1];

    for (int i = snk->size - 1; i > 0; i--) {
        snk->pos[i] = snk->pos[i - 1];
    }
    switch (snk->direction) {
        case UP_DIR:
            snk->pos[0].y--;
            break;
        case DOWN_DIR:
            snk->pos[0].y++;
            break;
        case LEFT_DIR:
            snk->pos[0].x--;
            break;
        case RIGHT_DIR:
            snk->pos[0].x++;
            break;
    }

    if (snk->pos[0].x == a->pos.x && snk->pos[0].y == a->pos.y) {
        snk->pos[snk->size] = snakeTail;
        snk->size++;
        a->eaten = TRUE;
    }
}