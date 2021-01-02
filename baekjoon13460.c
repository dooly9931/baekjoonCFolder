#include <stdio.h>
#define DEBUG 0

int stopLocaX[4][10][10], stopLocaY[4][10][10];

void resolve(int red, int blue, int *redNext, int *blueNext, int dl) {
    if (dl*(*redNext-red) > dl*(*blueNext-blue)) {
        (*redNext) -= dl;
    } else {
        (*blueNext) -= dl;
    }
}

int moveFunc(int redX, int redY, int blueX, int blueY, int move) {
    int i, min = 11, ret;
    int nextRedX, nextRedY, nextBlueX, nextBlueY;
#if DEBUG
    printf("red: (%d, %d), blue: (%d, %d), move = %d\n", redX, redY, blueX, blueY, move);
#endif
    if (move >= 10) return min;

    for (i=0 ; i<4 ; i++) {
        nextRedX = stopLocaX[i][redX][redY];
        nextRedY = stopLocaY[i][redX][redY];
        nextBlueX = stopLocaX[i][blueX][blueY];
        nextBlueY = stopLocaY[i][blueX][blueY];
        if (nextBlueX == 0 && nextBlueY == 0) {
            continue;
        } else if (nextRedX == 0 && nextRedY == 0) {
            if (min > move+1) min = move+1;
            continue;
        } else if (nextRedX == nextBlueX && nextRedY == nextBlueY) {
            if (i%2 == 0) {
                resolve(redX, blueX, &nextRedX, &nextBlueX, i-1);
            } else {
                resolve(redY, blueY, &nextRedY, &nextBlueY, 2-i);
            }
        }
        ret = moveFunc(nextRedX, nextRedY, nextBlueX, nextBlueY, move+1);
        if (min > ret) min = ret;
    }
    return min;
}

int main(void) {
    int N, M, i, j, k, x, y, redX, redY, blueX, blueY, ret;
    char plate[10][10], enter;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; // up 0, right 1, down 2, left 3

    scanf("%d %d%c", &N, &M, &enter);
    for (i=0 ; i<N ; i++) {
        for (j=0 ; j<M ; j++) {
            scanf("%c", &plate[i][j]);
            if (plate[i][j] == 'R') {
                redX = i; redY = j;
            } else if (plate[i][j] == 'B') {
                blueX = i; blueY = j;
            }
        }
        scanf("%c", &enter);
    }
    for (i=0 ; i<4 ; i++) {
        for (j=0 ; j<N ; j++) {
            for (k=0 ; k<M ; k++) {
                if (plate[j][k] == '.' || plate[j][k] == 'R' || plate[j][k] == 'B' || plate[j][k] == 'O') {
                    x = j; y = k;
                    while (plate[x+dx[i]][y+dy[i]] != '#' && plate[x][y] != 'O') {
                        x+=dx[i]; y+=dy[i];
                    }
                    if (plate[x][y] == 'O') {
                        stopLocaX[i][j][k] = 0; stopLocaY[i][j][k] = 0;
                    } else {
                        stopLocaX[i][j][k] = x; stopLocaY[i][j][k] = y;
                    }
                } else {
                    stopLocaX[i][j][k] = -1; stopLocaY[i][j][k] = -1;
                }
            }
        }
    }
#if DEBUG
    for (i=0 ; i<N ; i++) {
        for (j=0 ; j<M ; j++) {
            printf("%c", plate[i][j]);
        }
        printf("\n");
    }
    for (i=0 ; i<4 ; i++) {
        for (j=0 ; j<N ; j++) {
            for (k=0 ; k<M ; k++) {
                printf("(%d, %d) ", stopLocationX[i][j][k], stopLocationY[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
#endif
    ret = moveFunc(redX, redY, blueX, blueY, 0);
    printf("%d\n", (ret < 11 ? ret : -1));
    return 0;
}
