#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 20

typedef struct {
    int data[STACK_SIZE];
    int top;
} Stack;

void init_stack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int value) {
    if (s->top == STACK_SIZE - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->top++;
    s->data[s->top] = value;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow!\n");
        exit(1);
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

void selection_sort(int a[], int n) {
    Stack s;int i;
    init_stack(&s);
    for (i = 0; i < n; i++) {
        if (is_empty(&s) || a[i] >= s.data[s.top]) {
            push(&s, a[i]);
        } else {
            while (!is_empty(&s) && a[i] < s.data[s.top]) {
                a[i - (s.top + 1)] = pop(&s);
            }
            push(&s, a[i]);
        }
    }
    while (!is_empty(&s)) {
        a[n - (s.top + 1)] = pop(&s);
    }
}

int main() {
    int a[20], n,i;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the elements to be sorted: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    selection_sort(a, n);
    printf("The sorted elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}


