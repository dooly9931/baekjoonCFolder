#include <stdio.h>
#include <stdlib.h>

int a[5000001];

void Merge(int *a, int p, int q) {
    int *sorted = (int *)malloc((q-p+1) * sizeof(int));
    int i, j, k;
    i=p; j = (p+q)/2+1; k = 0;
    while (i < (p+q)/2+1 && j < q+1) {
        if (a[i] < a[j]) {
            sorted[k] = a[i];
            i++;
        } else {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    while (i < (p+q)/2+1) {
        sorted[k] = a[i];
        i++;
        k++;
    }
    while (j < q+1) {
        sorted[k] = a[j];
        j++;
        k++;
    }
    for (i=0 ; i<q-p+1 ; i++) {
        a[p+i] = sorted[i];
    }
    free(sorted);
}

void MergeSort(int *a, int p, int q) {
    if (p<q) {
        MergeSort(a, p, (p+q)/2);
        MergeSort(a, (p+q)/2+1, q);
        Merge(a, p, q);
    }
}

int main(void) {
    int n, k, i;
    scanf("%d %d", &n, &k);
    for (i=0 ; i<n ; i++) {
        scanf("%d", &a[i]);
    }

    MergeSort(a, 0, n-1);

    printf("%d\n", a[k-1]);
    return 0;
}
