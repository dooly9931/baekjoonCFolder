#include <stdio.h>

long long cnt[10];
long long unitWoZero[13][10];
long long unitWZero[13][10];

void process(long long n, long long decimal, int power) {
    long long num, residue;
    int i, highest = 0;

    if(n / decimal > 0) {
        if(power > 1) { // unit update
            unitWoZero[power][0] = unitWoZero[power - 1][0] + 9 * unitWZero[power - 1][0];
            for(i=1 ; i<=9 ; i++) {
                unitWoZero[power][i] = decimal / 10 + unitWoZero[power - 1][i] + 9 * unitWZero[power - 1][i];
            }
            for(i=0 ; i<=9 ; i++) {
                unitWZero[power][i] = decimal / 10 + 10 * unitWZero[power - 1][i];
            }
        }

        process(n, 10 * decimal, power + 1);

        num = (n / decimal) % 10;
        residue = n % decimal;
        if(n / decimal < 10) {
            highest = 1;
        } else {
            highest = 0;
        }

        if(highest == 1) {
            for(i=0 ; i<=9 ; i++) {
                cnt[i] = cnt[i] + unitWoZero[power][i] + (num - 1) * unitWZero[power][i];
            }
            for(i=1 ; i<num ; i++) {
                cnt[i] = cnt[i] + decimal;
            }
            cnt[num] = cnt[num] + residue + 1;
        } else {
            for(i=0 ; i<=9 ; i++) {
                cnt[i] = cnt[i] + num * unitWZero[power][i];
            }
            for(i=0 ; i<num ; i++) {
                cnt[i] = cnt[i] + decimal;
            }
            cnt[num] = cnt[num] + residue + 1;
        }
    }
}

int main(void) {
    long long n;
    int i;
    for(i=0 ; i<=9 ; i++) {
        cnt[i] = 0;
        unitWoZero[0][i] = 0;
        unitWoZero[1][i] = 1;
        unitWZero[0][i] = 0;
        unitWZero[1][i] = 1;
    }

    scanf("%d", &n);

    process(n, 1, 0);

    if(n >= 10) {
        cnt[0] = cnt[0] - 1;
    }

    for(i=0 ; i<=9 ; i++) {
        printf("%lld ", cnt[i]);
    }

    return 0;
}
