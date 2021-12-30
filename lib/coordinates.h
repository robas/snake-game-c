#ifndef COORDINATES_H
#define COORDINATES_H

typedef struct str_coordinate {
    int x;
    int y;
} Coordinates;

extern Coordinates UP;
extern Coordinates DOWN;
extern Coordinates LEFT;
extern Coordinates RIGHT;

#endif