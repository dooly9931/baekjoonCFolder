#include <stdio.h>

void copy(int (*arr1) [21], int (*arr2) [21], int n) {
    int i, j;
    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            arr2[i][j] = arr1[i][j];
        }
    }
}

void move(int (*arr) [21], int n, int level, int maxLevel, int *maxp);

void moveUP(int (*arr) [21], int n, int level, int maxLevel, int *maxp) {
    int i, j, k, limit, temp;

    for (j=0 ; j<n ; j++) {
        i = 0;
        limit = 0;
        k = 0;
        while (i < n) {
            while (i < n && arr[i][j] == 0) i++;
            if (i == n) break;
            if (k > limit && arr[k-1][j] == arr[i][j]) {
                arr[k-1][j] += arr[i][j];
                arr[i][j] = 0;
                limit = k;
            }
            else {
                temp = arr[i][j];
                arr[i][j] = 0;
                arr[k][j] = temp;
                k++;
            }
            i++;
        }
    }

    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            if (*maxp < arr[i][j]) {
                *maxp = arr[i][j];
            }
        }
    }
    move(arr, n, level+1, maxLevel, maxp);
}

void moveDOWN(int (*arr) [21], int n, int level, int maxLevel, int *maxp) {
    int i, j, k, limit, temp;

    for (j=0 ; j<n ; j++) {
        i = n-1;
        limit = n-1;
        k = n-1;
        while (i >= 0) {
            while (i >= 0 && arr[i][j] == 0) i--;
            if (i == -1) break;
            if (k < limit && arr[k+1][j] == arr[i][j]) {
                arr[k+1][j] += arr[i][j];
                arr[i][j] = 0;
                limit = k;
            }
            else {
                temp = arr[i][j];
                arr[i][j] = 0;
                arr[k][j] = temp;
                k--;
            }
            i--;
        }
    }

    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            if (*maxp < arr[i][j]) {
                *maxp = arr[i][j];
            }
        }
    }
    move(arr, n, level+1, maxLevel, maxp);
}

void moveLEFT(int (*arr) [21], int n, int level, int maxLevel, int *maxp) {
    int i, j, k, limit, temp;

    for (i=0 ; i<n ; i++) {
        j = 0;
        limit = 0;
        k = 0;
        while (j < n) {
            while (j < n && arr[i][j] == 0) j++;
            if (j == n) break;
            if (k > limit && arr[i][k-1] == arr[i][j]) {
                arr[i][k-1] += arr[i][j];
                arr[i][j] = 0;
                limit = k;
            }
            else {
                temp = arr[i][j];
                arr[i][j] = 0;
                arr[i][k] = temp;
                k++;
            }
            j++;
        }
    }

    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            if (*maxp < arr[i][j]) {
                *maxp = arr[i][j];
            }
        }
    }
    move(arr, n, level+1, maxLevel, maxp);
}

void moveRIGHT(int (*arr) [21], int n, int level, int maxLevel, int *maxp) {
    int i, j, k, limit, temp;

    for (i=0 ; i<n ; i++) {
        j = n-1;
        limit = n-1;
        k = n-1;
        while (j >= 0) {
            while (j >= 0 && arr[i][j] == 0) j--;
            if (j == -1) break;
            if (k < limit && arr[i][k+1] == arr[i][j]) {
                arr[i][k+1] += arr[i][j];
                arr[i][j] = 0;
                limit = k;
            }
            else {
                temp = arr[i][j];
                arr[i][j] = 0;
                arr[i][k] = temp;
                k--;
            }
            j--;
        }
    }

    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            if (*maxp < arr[i][j]) {
                *maxp = arr[i][j];
            }
        }
    }
    move(arr, n, level+1, maxLevel, maxp);
}

void move(int (*arr1) [21], int n, int level, int maxLevel, int *maxp) {
    int arr2[21][21];
    if (level < maxLevel) {
        copy(arr1, arr2, n);
        moveUP(arr2, n, level, maxLevel, maxp);
        copy(arr1, arr2, n);
        moveDOWN(arr2, n, level, maxLevel, maxp);
        copy(arr1, arr2, n);
        moveLEFT(arr2, n, level, maxLevel, maxp);
        copy(arr1, arr2, n);
        moveRIGHT(arr2, n, level, maxLevel, maxp);
    }
}

int main(void) {
    int n, i, j, max = 0;
    int plate[21][21];

    scanf("%d", &n);
    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            scanf("%d", &plate[i][j]);
        }
    }

    move(plate, n, 0, 5, &max);

    printf("%d\n", max);

    return 0;
}