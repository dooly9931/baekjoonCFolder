#include <stdio.h>

long long int GCD(long long int a, long long int b) {
    if (a % b == 0) return b;
    else return GCD(b, a%b);
}

int main(void) {
    long long int a, b, gcd, lcm;

    scanf("%lld %lld", &a, &b);

    gcd = GCD(a, b);
    lcm = a * b / gcd;

    printf("%lld\n", lcm);

    return 0;
}