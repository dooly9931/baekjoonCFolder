#include <stdio.h>
#define INF 101

int main(void) {
    int n, i, j, k, cnt = 0;
    int dist[101][101], check[101] = {0, };

    scanf("%d", &n);
    for (i=1 ; i<=n ; i++) {
        for (j=1 ; j<=n ; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = INF;
            }
        }
    }
    for (i=1 ; i<=n ; i++) {
        scanf("%d", &j);
        dist[i][j] = 1;
    }

    // Floyd-Warshall
    for (k=1 ; k<=n ; k++) {
        for (i=1 ; i<=n ; i++) {
            for (j=1 ; j<=n ; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // check cycles including self-loop
    for (i=1 ; i<=n ; i++) {
        if (check[i] == 0) {
            if (dist[i][i] == 1) { // self-loop
                check[i] = 1;
                cnt++;
            } else {
                k = i;
                for (j=k+1 ; j<=n ; j++) {
                    if (dist[k][j] < INF && dist[j][k] < INF) { // cycle with at least 2 vertices
                        check[k] = 1;
                        cnt++;
                        k = j;
                    }
                }
                if (i != k) {
                    check[k] = 1;
                    cnt++;
                }
            }
        }
    }

    printf("%d\n", cnt);
    for (i=1 ; i<=n ; i++) {
        if (check[i] == 1) {
            printf("%d\n", i);
        }
    }

    return 0;
}