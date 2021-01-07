#include <stdio.h>

void brute(int (*s) [21], int *team, int start, int link, int index, int n, int *minp) {
    if (index == n) {
        int startTeam = 0, linkTeam = 0, i, j, min;
        for (i=0 ; i<n ; i++) {
            for (j=0 ; j<i ; j++) {
                if (team[i] == 1 && team[j] == 1) {
                    startTeam += s[i][j];
                    startTeam += s[j][i];
                } else if (team[i] == -1 && team[j] == -1) {
                    linkTeam += s[i][j];
                    linkTeam += s[j][i];
                }
            }
        }
        min = startTeam > linkTeam ? startTeam - linkTeam : linkTeam - startTeam;
        if (*minp > min) {
            *minp = min;
        }
    } else {
        if (n - index > n/2 - link) {
            team[index] = 1;
            brute(s, team, start+1, link, index+1, n, minp);
        }
        if (n - index > n/2 - start) {
            team[index] = -1;
            brute(s, team, start, link+1, index+1, n, minp);
        }
    }
}

int main(void) {
    int n, i, j, min = 10000;
    int s[21][21], team[21];

    scanf("%d", &n);
    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            scanf("%d", &s[i][j]);
        }
    }
    team[0] = 1;

    brute(s, team, 1, 0, 1, n, &min);

    printf("%d\n", min);

    return 0;
}