#include <stdio.h>
#include <stdlib.h>

typedef struct __node {
    int row;
    int col;
    struct __node *next;
} Node;

typedef struct __stack {
    Node *head;
} Stack;

void stack_init(Stack *s) {
    s->head = NULL;
}

void stack_push(Stack *s, int row, int col) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->row = row;
    newNode->col = col;
    newNode->next = s->head;
    s->head = newNode;
}

int stack_empty(Stack *s) {
    if (s->head == NULL) return 1;
    else return 0;
}

void stack_pop(Stack *s, int *row, int *col) {
    Node *node = s->head;
    *row = node->row;
    *col = node->col;
    s->head = node->next;
    free(node);
}

int main(void) {
    int n, i, j, townCnt = 0, peopleCnt, x, y, temp;
    char c, e;
    int a[25][25], town[170] = {0, };
    Stack s;

    scanf("%d%c", &n, &e);
    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            scanf("%c", &c);
            a[i][j] = c - '0';
        }
        scanf("%c", &e);
    }

    stack_init(&s);
    for (i=0 ; i<n ; i++) {
        for (j=0 ; j<n ; j++) {
            if (a[i][j] == 1) { // town not yet checked
                townCnt++;
                peopleCnt = 1;
                a[i][j] = -1;
                stack_push(&s, i, j);
                // DFS
                while (!stack_empty(&s)) {
                    stack_pop(&s, &x, &y);
                    if (x != 0 && a[x-1][y] == 1) {
                        peopleCnt++;
                        a[x-1][y] = -1;
                        stack_push(&s, x-1, y);
                    }
                    if (x != n-1 && a[x+1][y] == 1) {
                        peopleCnt++;
                        a[x+1][y] = -1;
                        stack_push(&s, x+1, y);
                    }
                    if (y != 0 && a[x][y-1] == 1) {
                        peopleCnt++;
                        a[x][y-1] = -1;
                        stack_push(&s, x, y-1);
                    }
                    if (y != n-1 && a[x][y+1] == 1) {
                        peopleCnt++;
                        a[x][y+1] = -1;
                        stack_push(&s, x, y+1);
                    }
                }
                town[townCnt-1] = peopleCnt;
            }
        }
    }

    for (i=0 ; i<townCnt-1 ; i++) {
        for (j=0 ; j<townCnt-1-i ; j++) {
            if (town[j] > town[j+1]) {
                temp = town[j];
                town[j] = town[j+1];
                town[j+1] = temp;
            }
        }
    }

    printf("%d\n", townCnt);
    for (i=0 ; i<townCnt ; i++) {
        printf("%d\n", town[i]);
    }

    return 0;
}