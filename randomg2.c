#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8

typedef struct {
    int data[MAX_SIZE];
    int top;
} stack;

void init(stack* s) {
    s->top = -1;
}

void push(stack* s, int x) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->data[++s->top] = x;
}

int pop(stack* s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return s->data[s->top--];
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printarr(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void randomize(int a[], int n) {
    int i;
    stack s;
    init(&s);
    srand(time(NULL));
    for (i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&a[i], &a[j]);
        push(&s, a[i]);
    }
    push(&s, a[0]);
    for (i = 0; i < n; i++) {
        a[i] = pop(&s);
    }
}

int main() {
    int a[MAX_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};
    randomize(a, MAX_SIZE);
    printarr(a, MAX_SIZE);

    return 0;
}
