#include <stdio.h> // DP

int a[10000001];

int main(void) {
    int N, M, i, j;
    int m[101], c[101];
    const int INF = 10001;

    scanf("%d %d", &N, &M);
    for (i=0 ; i<N ; i++) {
        scanf("%d", &m[i]);
    }
    for (i=0 ; i<N ; i++) {
        scanf("%d", &c[i]);
    }

    for (j=1 ; j<=M ; j++) {
        a[j] = INF;
    }
    for (i=0 ; i<N ; i++) {
        for (j=M ; j>m[i] ; j--) {
            if (a[j] > a[j-m[i]] + c[i]) {
                a[j] = a[j-m[i]] + c[i];
            }
        }
        for (j=m[i] ; j>0 ; j--) {
            if (a[j] > c[i]) {
                a[j] = c[i];
            }
        }
    }

    printf("%d\n", a[M]);

    return 0;
}