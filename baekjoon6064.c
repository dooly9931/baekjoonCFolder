#include <stdio.h>

int gcd(int a, int b) {
    if(a < b) {
        return gcd(b, a);
    } else {
        if(a % b == 0) {
            return b;
        } else {
            return gcd(b, a % b);
        }
    }
}

int main(void) {
    int t, i, m, n, x, y, GCD, m_prime, j, ans;

    scanf("%d", &t);
    for(i=0 ; i<t ; i++) {
        ans = -1;
        scanf("%d %d %d %d", &m, &n, &x, &y);
        GCD = gcd(m, n);
        m_prime = n / GCD;
        for(j=0 ; j<m_prime ; j++) {
            if((m * j + x - 1) % n + 1 == y) {
                ans = m * j + x;
                break;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}