#include <stdio.h>

int roadCheck(int (*map) [101], int x0, int y0, int dx, int dy, int n, int l) {
    int x = x0, y = y0, consec = 1, i;

    while (x < n-1+dy && y < n-1+dx) { // allowing up to n-1 for not-moving direction
        if (map[x+dx][y+dy] - map[x][y] == 0) {
            x = x + dx; y = y + dy;
            consec++;
        } else if (map[x+dx][y+dy] - map[x][y] == 1) {
            if (consec < l) {
                return 0;
            } else {
                x = x + dx; y = y + dy;
                consec = 1;
            }
        } else if (map[x+dx][y+dy] - map[x][y] == -1) {
            for (i=2 ; i<=l ; i++) {
                if (map[x+dx][y+dy] != map[x+dx*i][y+dy*i]) {
                    return 0;
                }
            }
            x = x + dx * l; y = y + dy * l;
            consec = 0;
        } else {
            return 0;
        }
    }

    return 1;
}

int main(void) {
    int n, l, i, j, cnt = 0;
    int map[101][101];

    scanf("%d %d", &n, &l);
    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    for (i=0 ; i<n ; i++) {
        cnt += roadCheck(map, i, 0, 0, 1, n, l);
        cnt += roadCheck(map, 0, i, 1, 0, n, l);
    }

    printf("%d\n", cnt);

    return 0;
}