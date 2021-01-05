#include <stdio.h>

void recurrence(int (*max) [11][11][11], int (*min) [11][11][11], int *arr, int n1, int n2, int n3, int n4) {
    if (max[n1][n2][n3][n4] != -1000000001) return;
    
    if (n1 > 0) {
        if (max[n1-1][n2][n3][n4] == -1000000001) recurrence(max, min, arr, n1-1, n2, n3, n4);
        if (max[n1][n2][n3][n4] < max[n1-1][n2][n3][n4] + arr[n1+n2+n3+n4]) {
            max[n1][n2][n3][n4] = max[n1-1][n2][n3][n4] + arr[n1+n2+n3+n4];
        }
        if (min[n1][n2][n3][n4] > min[n1-1][n2][n3][n4] + arr[n1+n2+n3+n4]) {
            min[n1][n2][n3][n4] = min[n1-1][n2][n3][n4] + arr[n1+n2+n3+n4];
        }
    }
    if (n2 > 0) {
        if (max[n1][n2-1][n3][n4] == -1000000001) recurrence(max, min, arr, n1, n2-1, n3, n4);
        if (max[n1][n2][n3][n4] < max[n1][n2-1][n3][n4] - arr[n1+n2+n3+n4]) {
            max[n1][n2][n3][n4] = max[n1][n2-1][n3][n4] - arr[n1+n2+n3+n4];
        }
        if (min[n1][n2][n3][n4] > min[n1][n2-1][n3][n4] - arr[n1+n2+n3+n4]) {
            min[n1][n2][n3][n4] = min[n1][n2-1][n3][n4] - arr[n1+n2+n3+n4];
        }
    }
    if (n3 > 0) {
        if (max[n1][n2][n3-1][n4] == -1000000001) recurrence(max, min, arr, n1, n2, n3-1, n4);
        if (max[n1][n2][n3][n4] < max[n1][n2][n3-1][n4] * arr[n1+n2+n3+n4]) {
            max[n1][n2][n3][n4] = max[n1][n2][n3-1][n4] * arr[n1+n2+n3+n4];
        }
        if (min[n1][n2][n3][n4] > min[n1][n2][n3-1][n4] * arr[n1+n2+n3+n4]) {
            min[n1][n2][n3][n4] = min[n1][n2][n3-1][n4] * arr[n1+n2+n3+n4];
        }
    }
    if (n4 > 0) {
        if (max[n1][n2][n3][n4-1] == -1000000001) recurrence(max, min, arr, n1, n2, n3, n4-1);
        if (max[n1][n2][n3][n4] < max[n1][n2][n3][n4-1] / arr[n1+n2+n3+n4]) {
            max[n1][n2][n3][n4] = max[n1][n2][n3][n4-1] / arr[n1+n2+n3+n4];
        }
        if (min[n1][n2][n3][n4] > min[n1][n2][n3][n4-1] / arr[n1+n2+n3+n4]) {
            min[n1][n2][n3][n4] = min[n1][n2][n3][n4-1] / arr[n1+n2+n3+n4];
        }
    }
}

int main(void) {
    int n, i, j, k, l, n1, n2, n3, n4;
    int arr[100], max[11][11][11][11], min[11][11][11][11];

    scanf("%d", &n);
    for (i=0 ; i<n ; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);

    for (i=0 ; i<=n1 ; i++) {
        for (j=0 ; j<=n2 ; j++) {
            for (k=0 ; k<=n3 ; k++) {
                for (l=0 ; l<=n4 ; l++) {
                    max[i][j][k][l] = -1000000001;
                    min[i][j][k][l] = 1000000001;
                }
            }
        }
    }
    max[1][0][0][0] = min[1][0][0][0] = arr[0] + arr[1];
    max[0][1][0][0] = min[0][1][0][0] = arr[0] - arr[1];
    max[0][0][1][0] = min[0][0][1][0] = arr[0] * arr[1];
    max[0][0][0][1] = min[0][0][0][1] = arr[0] / arr[1];

    recurrence(max, min, arr, n1, n2, n3, n4);

    printf("%d\n%d\n", max[n1][n2][n3][n4], min[n1][n2][n3][n4]);

    return 0;
}