#include <stdio.h>

int prime[1000001]; // prime numbers larger than 2

void checkPrime() {
    int i, j;
    for(i=3 ; i<1000001 ; i++) {
        prime[i] = 1;
        for(j=2 ; j<i ; j++) {
            if(j * j > i) {
                break;
            }
            if(i % j == 0) {
                prime[i] = 0;
                break;
            }
        }
    }
}

int main(void) {
   int n, i;
   checkPrime();
   do {
       scanf("%d", &n);
       if(n != 0) {
           for(i=1 ; i<((n/2) + 1) / 2 ; i++) {
               if(prime[2 * i + 1] == 1 && prime[n - 2 * i - 1] == 1) {
                   printf("%d = %d + %d\n", n, 2 * i + 1, n - 2 * i - 1);
                   break;
               }
           }
       } 
   } while(n != 0);

   return 0;
}
