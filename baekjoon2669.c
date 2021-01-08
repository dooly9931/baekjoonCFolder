#include <stdio.h>

int main(void) {
    int i, j, k, included, area = 0;
    int x1[4], y1[4], x2[4], y2[4];

    for (i=0 ; i<4 ; i++) {
        scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
    }

    for (i=1 ; i<=100 ; i++) {
        for (j=1 ; j<=100 ; j++) {
            included = 0;
            for (k=0 ; k<4 ; k++) {
                if (x1[k] <= i && i < x2[k] && y1[k] <= j && j < y2[k]) included = 1;
            }
            area += included;
        }
    }

    printf("%d\n", area);

    return 0;
}