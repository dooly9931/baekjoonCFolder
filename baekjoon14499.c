#include <stdio.h>

void moveEast(int *dice, int *nextRoom) {
    int temp = dice[2];

    dice[2] = dice[0];
    dice[0] = dice[3];
    dice[3] = dice[5];

    if (*nextRoom == 0) {
        dice[5] = temp;
        *nextRoom = temp;
    } else {
        dice[5] = *nextRoom;
        *nextRoom = 0;
    }
}

void moveWest(int *dice, int *nextRoom) {
    int temp = dice[3];

    dice[3] = dice[0];
    dice[0] = dice[2];
    dice[2] = dice[5];

    if (*nextRoom == 0) {
        dice[5] = temp;
        *nextRoom = temp;
    } else {
        dice[5] = *nextRoom;
        *nextRoom = 0;
    }
}

void moveNorth(int *dice, int *nextRoom) {
    int temp = dice[1];

    dice[1] = dice[0];
    dice[0] = dice[4];
    dice[4] = dice[5];

    if (*nextRoom == 0) {
        dice[5] = temp;
        *nextRoom = temp;
    } else {
        dice[5] = *nextRoom;
        *nextRoom = 0;
    }
}

void moveSouth(int *dice, int *nextRoom) {
    int temp = dice[4];

    dice[4] = dice[0];
    dice[0] = dice[1];
    dice[1] = dice[5];

    if (*nextRoom == 0) {
        dice[5] = temp;
        *nextRoom = temp;
    } else {
        dice[5] = *nextRoom;
        *nextRoom = 0;
    }
}

int main(void) {
    int n, m, x, y, k, i, j, move;
    int plate[20][20], dice[6] = {0, }, dx[5] = {0, 0, 0, -1, 1}, dy[5] = {0, 1, -1, 0, 0};
    void (*moveFunc[5]) (int *, int *) = {NULL, moveEast, moveWest, moveNorth, moveSouth};

    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<m ; j++) {
            scanf("%d", &plate[i][j]);
        }
    }

    for (i=0 ; i<k ; i++) {
        scanf("%d", &move);
        if (x + dx[move] < 0 || x + dx[move] > n-1 || y + dy[move] < 0 || y + dy[move] > m-1)
            continue;
        x = x + dx[move]; y = y + dy[move];
        moveFunc[move](dice, &plate[x][y]);
        printf("%d\n", dice[0]);
    }

    return 0;
}