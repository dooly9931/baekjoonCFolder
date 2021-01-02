#include <stdio.h>

int main(void) {
    int apple[102][102], arriveTime[102][102];
    int n, k, x, y, i, j, length = 1, currTime = 1;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}, mode = 0;
    int l, changeDirectionTime[101], changeDirection[101], nextChange = 0;
    char direction, e;

    scanf("%d", &n);
    scanf("%d", &k);
    for (i=1 ; i<n+1 ; i++) {
        for (j=1 ; j<n+1 ; j++) {
            apple[i][j] = 0;
            arriveTime[i][j] = -102;
        }
    }
    for (i=0 ; i<k ; i++) {
        scanf("%d %d", &x, &y);
        apple[x][y] = 1;
    }
    arriveTime[1][1] = 0;

    scanf("%d", &l);
    for (i=0 ; i<l ; i++) {
        scanf("%d %c%c", &changeDirectionTime[i], &direction, &e);
        changeDirection[i] = (direction == 'D' ? 1 : -1);
    }
    changeDirectionTime[l] = -1;

    x = 1; y = 1;
    while (1) {
        x = x+dx[mode]; y = y + dy[mode];
        if (x == 0 || x == n+1 || y == 0 || y == n+1) break;
        if (arriveTime[x][y] + length >= currTime) break;
        if (apple[x][y] == 1) {
            length++;
            apple[x][y] = 0;
        }
        arriveTime[x][y] = currTime;

        if (changeDirectionTime[nextChange] == currTime) {
            mode = (mode+changeDirection[nextChange]+4) % 4;
            nextChange++;
        }
        currTime++;
    }

    printf("%d\n", currTime);

    return 0;
}