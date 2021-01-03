#include <stdio.h>

int main(void) {
    int n, i;
    int t[15], p[15], dpTable[16] = {0, }; // dpTable[i] : optimal smaller solution when working for i ~ n-1 day. dpTable[n] : always 0

    scanf("%d", &n);
    for (i=0 ; i<n ; i++) {
        scanf("%d %d", &t[i], &p[i]);
    }

    for (i=n-1 ; i>=0 ; i--) {
        if (i + t[i] <= n) {
            dpTable[i] = p[i] + dpTable[i+t[i]] > dpTable[i+1] ? p[i] + dpTable[i+t[i]] : dpTable[i+1]; // recurrence relation
        } else {
            dpTable[i] = dpTable[i+1]; // recurrence relation
        }
    }

    printf("%d\n", dpTable[0]);

    return 0;
}