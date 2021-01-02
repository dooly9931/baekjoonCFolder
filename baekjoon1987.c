#include <stdio.h>

char a[21][21];
char history[28];
int r, c, max = 0;

int check(int move, char newChar) {
    int i;
    for(i=move ; i>0 ; i--) {
        if(history[i] == newChar) {
            return 0;
        }
    }
    return 1;
}

void trace(int move, int x, int y) {
    int i;
    history[move] = a[x][y];
    if(max < move) {
        max = move;
    }
    if(check(move, a[x + 1][y]) > 0 && x + 1 < r) {
        trace(move + 1, x + 1, y);
    }
    if(check(move, a[x][y + 1]) > 0 && y + 1 < c) {
        trace(move + 1, x, y + 1);
    }
    if(check(move, a[x - 1][y]) > 0 && x > 0) {
        trace(move + 1, x - 1, y);
    }
    if(check(move, a[x][y - 1]) > 0 && y > 0) {
        trace(move + 1, x, y - 1);
    }
}

int main(void) {
    char spacebar;
    int i, j;

    scanf("%d %d", &r, &c);
    scanf("%c", &spacebar);
    for(i=0 ; i<r ; i++) {
        for(j=0 ; j<c ; j++) {
            scanf("%c", &a[i][j]);
        }
        scanf("%c", &spacebar);
    }

    trace(1, 0, 0);

    printf("%d\n", max);

    return 0;
}
