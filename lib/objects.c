#include "objects.h"

#include <ncurses.h>

#include "board.h"

Snake initializeSnake(int x, int y) {
    Snake snk;
    snk.size = 3;
    snk.direction = RIGHT_DIR;
    snk.pos[0].x = x + 2;
    snk.pos[0].y = y;
    snk.pos[1].x = x + 1;
    snk.pos[1].y = y;
    snk.pos[2].x = x;
    snk.pos[2].y = y;
    return snk;
}

Apple initializeApple(WINDOW *field, Snake snk) {
    Apple a;
    a.eaten = FALSE;
    a.pos = getRandomPositionOtherThan(field, snk.pos, snk.size);
    return a;
}