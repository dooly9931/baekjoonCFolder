#include <stdio.h>

int a[1000001];

int main(void) {
    int n, i, b, c;
    long long cnt = 0;

    scanf("%d", &n);
    cnt = n;
    for(i = 0 ; i < n ; i = i + 1) {
        scanf("%d",&a[i]);
    }
    scanf("%d %d", &b, &c);

    for(i = 0 ; i < n ; i = i + 1) {
        if((a[i] - b) > 0) {
            if((a[i] - b) % c == 0) {
                cnt = cnt + (a[i] - b) / c;
            } else {
                cnt = cnt + (a[i] - b) / c + 1;
            }
        }
    }

    printf("%lld\n", cnt);

    return 0;
}
