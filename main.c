#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define boardWidth 12
#define boardHeight 12
#define initialXPos 1
#define initialYPos 1

typedef struct str_position {
    int x;
    int y;
} Coordinates;

char board[boardWidth][boardHeight];
Coordinates playerPos = {initialXPos, initialYPos};
int cmd;

Coordinates up = {0, -1};
Coordinates down = {0, 1};
Coordinates left = {-1, 0};
Coordinates right = {1, 0};

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

void configureBoard() {
    configureEmptyBoard();
    pinOnBoard(playerPos, 'x');
}

Coordinates getNewPosition(Coordinates movement) {
    Coordinates newPos;
    int newX = playerPos.x + movement.x;
    int newY = playerPos.y + movement.y;

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

void movePlayer(Coordinates movement) {
    pinOnBoard(playerPos, ' ');
    playerPos = getNewPosition(movement);

    pinOnBoard(playerPos, 'x');
}

int handleCmd() {
    /*switch (cmd) {
        case lala:
            lalala;
            break;
        default:*/
    cmd = getchar();
    switch (cmd) {
        case 'w':
            movePlayer(up);
            break;
        case 'a':
            movePlayer(left);
            break;
        case 's':
            movePlayer(down);
            break;
        case 'd':
            movePlayer(right);
            break;
        default:
            break;
    }
    return cmd;
}

int main() {
    configureBoard();
    cmd = 0;

    while (cmd != 27) {
        drawBoard();
        handleCmd();

        // sleep(1);
    }
}