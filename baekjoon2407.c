#include <stdio.h>
#define MAXNUM 1000000000000000000 // 10^18, smaller than half of positive max of long long int
#define LAYERNUM 6 // we need at least 10^(18*LAYERNUM)
#define MAXN 100 // max value of n and m (nCm)

void combination(int n, int m, long long int (*dpTable) [MAXN+1][MAXN+1]) {
    if (dpTable[0][n][m] != -1) return;

    if (dpTable[0][n-1][m-1] == -1) combination(n-1, m-1, dpTable);

    if (dpTable[0][n-1][m] == -1) combination(n-1, m, dpTable);

    long long int overflow = 0;
    int i;
    for (i=0 ; i<LAYERNUM ; i++) {
        dpTable[i][n][m] = (dpTable[i][n-1][m-1] + dpTable[i][n-1][m] + overflow) % MAXNUM;
        overflow = (dpTable[i][n-1][m-1] + dpTable[i][n-1][m] + overflow) / MAXNUM;
    }
}

int main(void) {
    int n, m, i, j, k;
    long long int dpTable[LAYERNUM][MAXN+1][MAXN+1];
    
    scanf("%d %d", &n, &m);
    for (i=0 ; i<MAXN+1 ; i++) {
        for (j=0 ; j<MAXN+1 ; j++) {
            dpTable[0][i][j] = -1;
        }
        dpTable[0][i][0] = 1;
        dpTable[0][i][i] = 1;
    }
    for (i=1 ; i<LAYERNUM ; i++) {
        for (j=0 ; j<MAXN+1 ; j++) {
            for (k=0 ; k<MAXN+1 ; k++) {
                dpTable[i][j][k] = 0;
            }
        }
    }

    combination(n, m, dpTable);

    for (i=LAYERNUM-1 ; i>=0 ; i--) {
        if (dpTable[i][n][m] != 0) {
            printf("%lld", dpTable[i][n][m]);
        }
    }
    printf("\n");

    return 0;
}
