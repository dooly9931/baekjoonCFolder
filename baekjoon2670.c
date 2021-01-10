#include <stdio.h>

int main(void) {
    int n, i;
    double num[10001], dp[10001], max;

    scanf("%d", &n);
    for (i=0 ; i<n ; i++) {
        scanf("%lf", &num[i]);
    }
    dp[0] = num[0];
    max = num[0];
    for (i=1 ; i<n ; i++) {
        dp[i] = (dp[i-1] > 1 ? dp[i-1] : 1) * num[i];
        if (max < dp[i]) max = dp[i];
    }

    printf("%.3lf\n", max);

    return 0;
}