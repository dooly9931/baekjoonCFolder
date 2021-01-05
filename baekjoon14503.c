#include <stdio.h>

int main(void) {
    int n, m, r, c, d, i, j, dir, check, cnt = 0;
    int plate[50][50], dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);
    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<m ; j++) {
            scanf("%d", &plate[i][j]);
        }
    }
    dir = d;
    check = 0;
    while(check != 4 || plate[r+dr[(dir+2)%4]][c+dc[(dir+2)%4]] != 1) {
        plate[r][c] = 2;
        if (check == 4) {
            r -= dr[dir]; c -= dc[dir];
            check = 0;
            continue;
        }
        dir = (dir+3)%4;
        if (plate[r+dr[dir]][c+dc[dir]] == 0) {
            r += dr[dir]; c += dc[dir];
            check = 0;
        } else {
            check++;
        }
    }

    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<m ; j++) {
            if (plate[i][j] == 2) {
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);

    return 0;
}