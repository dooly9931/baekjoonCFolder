#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(char *s1, char *s2) {
    if (strlen(s1) < strlen(s2)) {
        return -1;
    } else if (strlen(s1) > strlen(s2)) {
        return 1;
    } else {
        return strcmp(s1, s2);
    }
}

void swap(char **s, int i, int j) {
    char *temp;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}

int main(void) {
    int n, i, j, heap_size;
    char enter;
    char *temp, *prev_str;

    scanf("%d%c", &n, &enter);
    heap_size = n;

    char **s = (char **)malloc(n * sizeof(char *));
    for(i=0 ; i<n ; i++) {
        s[i] = (char *)malloc(51 * sizeof(char));
        scanf("%s", s[i]);
    }

    /* Build MaxHeap */
    for(i=0 ; i<n ; i++) {
        j = i;
        while(j > 0 && compare(s[j], s[(j - 1) / 2]) > 0) {
            swap(s, j, (j - 1) / 2);
            j = (j - 1) / 2;
        }
    }

    while (heap_size > 0) {
        swap(s, 0, --heap_size);
        j = 0;
        while(2 * j + 1 < heap_size) {
            if(2 * j + 2 < heap_size) {
                if(compare(s[2 * j + 1], s[2 * j + 2]) >= 0 && compare(s[2 * j + 1], s[j]) > 0) {
                    swap(s, j, 2 * j + 1);
                    j = 2 * j + 1;
                } else if(compare(s[2 * j + 1], s[2 * j + 2]) <= 0 && compare(s[2 * j + 2], s[j]) > 0) {
                    swap(s, j, 2 * j + 2);
                    j = 2 * j + 2;
                } else {
                    break;
                }
            } else {
                if(compare(s[2 * j + 1], s[j]) > 0) {
                    swap(s, j, 2 * j + 1);
                    j = 2 * j + 1;
                } else {
                    break;
                }
            }
        }
    }

    prev_str = "";
    for (i=0 ; i<n ; i++) {
        if (strcmp(prev_str, s[i]) != 0) {
            printf("%s\n", s[i]);
            prev_str = s[i];
        }
    }

    for (i=0 ; i<n ; i++) {
        free(s[i]);
    }
    free(s);

    return 0;
}
