#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000

#define __ARRAY_LIST_BASE_ 0
#define __LINKED_LIST_BASE_ 1

#if __ARRAY_LIST_BASE_

typedef struct __stack_ {
    int *arr;
    int length;
    int nelem;
} Stack;

int init_stack(Stack *s) {
    s->arr = (int *)malloc(100 * sizeof(int));
    if (s->arr == NULL) return -1;
    s->length = 100;
    s->nelem = 0;
    return 0;
}

int push(Stack *s, int x) { // O(1)
    if (s->length == s->nelem) {
        s->length += 100;
        s->arr = realloc(s->arr, (s->length) * sizeof(int));
        if (s->arr == NULL) {
            perror("realloc");
            return -1;
        }
    }
    (s->arr)[s->nelem] = x;
    s->nelem += 1;
}

int empty(Stack *s) { // O(1)
    if (s->nelem == 0) return 1;
    else return 0;
}

int pop(Stack *s) { // O(1)
    if (empty(s)) return -1;
    else return (s->arr)[--(s->nelem)];
}

int size(Stack *s) { // O(1)
    return s->nelem;
}

int top(Stack *s) { // O(1)
    if (empty(s)) return -1;
    else return (s->arr)[(s->nelem)-1];
}

void delete_stack(Stack *s) {
    free(s->arr);
}

int main(void) {
    int n, i, x, p, len, t;
    char command[7], enter;
    Stack s;

    scanf("%d", &n);
    if (init_stack(&s) == -1) {
        printf("failed to initialize stack\n");
        return 0;
    }

    for (i=0 ; i<n ; i++) {
        scanf("%s", command);
        if (strcmp(command, "push") == 0) {
            scanf("%d%c", &x, &enter);
            if (push(&s, x) == -1) return 0;
        } else if (strcmp(command, "pop") == 0) {
            p = pop(&s);
            printf("%d\n", p);
        } else if (strcmp(command, "size") == 0) {
            len = size(&s);
            printf("%d\n", len);
        } else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty(&s));
        } else if (strcmp(command, "top") == 0) {
            if ((t = top(&s)) == -1) printf("-1\n");
            else printf("%d\n", t);
        } else {
            printf("invalid command");
            while (getchar() != '\n');
        }
    }
    delete_stack(&s);

    return 0;
}

#endif

#if __LINKED_LIST_BASE_

typedef struct __node_ {
    int value;
    struct __node_ *next;
} Node;

typedef struct __stack_ {
    Node *head;
    int nelem;
} Stack;

int init_stack(Stack *s) {
    s->head = (Node *)malloc(sizeof(Node));
    if (s->head == NULL) return -1;
    s->head->next = NULL;
    s->nelem = 0;
    return 0;
}

int push(Stack *s, int x) { // O(1)
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return -1;
    newNode->value = x;
    newNode->next = s->head->next;
    s->head->next = newNode;
    s->nelem += 1;
    return 0;
}

int empty(Stack *s) { // O(1)
    if (s->nelem == 0) return 1;
    else return 0;
}

int pop(Stack *s) { // O(1)
    if (empty(s)) return -1;
    Node *node = s->head->next;
    int ret = node->value;
    s->head->next = node->next;
    free(node);
    s->nelem -= 1;
    return ret;
}

int size(Stack *s) { // O(1)
    return s->nelem;
}

int top(Stack *s) { // O(1)
    if (empty(s)) return -1;
    else return s->head->next->value;
}

void delete_stack(Stack *s) {
    while (!empty(s)) {
        pop(s);
    }
    free(s->head);
}

int main(void) {
    int n, i, x, p, len, t;
    char command[7], enter;
    Stack s;

    scanf("%d", &n);
    if (init_stack(&s) == -1) {
        printf("failed to initialize stack\n");
        return 0;
    }

    for (i=0 ; i<n ; i++) {
        scanf("%s", command);
        if (strcmp(command, "push") == 0) {
            scanf("%d%c", &x, &enter);
            if (push(&s, x) == -1) return 0;
        } else if (strcmp(command, "pop") == 0) {
            p = pop(&s);
            printf("%d\n", p);
        } else if (strcmp(command, "size") == 0) {
            len = size(&s);
            printf("%d\n", len);
        } else if (strcmp(command, "empty") == 0) {
            printf("%d\n", empty(&s));
        } else if (strcmp(command, "top") == 0) {
            if ((t = top(&s)) == -1) printf("-1\n");
            else printf("%d\n", t);
        } else {
            printf("invalid command");
            while (getchar() != '\n');
        }
    }
    delete_stack(&s);

    return 0;
}

#endif