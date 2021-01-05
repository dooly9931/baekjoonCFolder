#include <stdio.h>
#include <stdlib.h>

typedef struct __node {
    int num;
    struct __node *next;
} Node;

typedef struct __stack {
    Node *head;
} Stack;

void init_stack(Stack *s) {
    s->head = (Node *)malloc(sizeof(Node));
    s->head->next = NULL;
}

void stack_push(Stack *s, int x) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->num = x;
    newNode->next = s->head->next;
    s->head->next = newNode;
}

int stack_empty(Stack *s) {
    if (s->head->next == NULL) return 1;
    else return 0;
}

int stack_pop(Stack *s) {
    Node *node = s->head->next;
    s->head->next = node->next;
    int ret = node->num;
    free(node);
    return ret;
}

void wallPlate(int (*plate) [8], int (*walledPlate) [8]);

int main(void) {
    int n, m, i, j, k, l, pos, x, y, cnt, max = 0;
    int plate[8][8], walledPlate[8][8];
    Stack s;

    init_stack(&s);

    scanf("%d %d", &n, &m);
    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<m ; j++) {
            scanf("%d", &plate[i][j]);
        }
    }

    for (i=0 ; i<n*m-2 ; i++) {
        if (plate[i/m][i%m] != 0) continue;
        plate[i/m][i%m] = 1;

        for (j=i+1 ; j<n*m-1 ; j++) {
            if (plate[j/m][j%m] != 0) continue;
            plate[j/m][j%m] = 1;

            for (k=j+1 ; k<n*m ; k++) {
                if  (plate[k/m][k%m] != 0) continue;
                plate[k/m][k%m] = 1;

                for (l=0 ; l<n*m ; l++) {
                    walledPlate[l/m][l%m] = plate[l/m][l%m];
                    if (plate[l/m][l%m] == 2) stack_push(&s, l);
                }
                // DFS
                while (!stack_empty(&s)) {
                    pos = stack_pop(&s);
                    x = pos/m; y = pos%m;
                    if (x > 0 && walledPlate[x-1][y] == 0) {
                        walledPlate[x-1][y] = 2;
                        stack_push(&s, (x-1)*m+y);
                    }
                    if (x < n-1 && walledPlate[x+1][y] == 0) {
                        walledPlate[x+1][y] = 2;
                        stack_push(&s, (x+1)*m+y);
                    }
                    if (y > 0 && walledPlate[x][y-1] == 0) {
                        walledPlate[x][y-1] = 2;
                        stack_push(&s, x*m+y-1);
                    }
                    if (y < m-1 && walledPlate[x][y+1] == 0) {
                        walledPlate[x][y+1] = 2;
                        stack_push(&s, x*m+y+1);
                    }
                }
                cnt = 0;
                for (l=0 ; l<n*m ; l++) {
                    if (walledPlate[l/m][l%m] == 0) cnt++;
                }
                if (max < cnt) {
                    max = cnt;
                }
                plate[k/m][k%m] = 0;
            }
            plate[j/m][j%m] = 0;
        }
        plate[i/m][i%m] = 0;
    }

    printf("%d\n", max);

    return 0;
}