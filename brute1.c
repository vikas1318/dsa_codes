#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int x) {
    s->top++;
    s->data[s->top] = x;
}

int pop(Stack *s) {
    int x = s->data[s->top];
    s->top--;
    return x;
}

int is_empty(Stack *s) {
    return s->top == -1;
}

void bubble_sort(int a[], int n) {
    Stack s;
    init(&s);
int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        push(&s, a[n - 1 - i]);
    }

    printf("Sorted array: ");
    while (!is_empty(&s)) {
        printf("%d ", pop(&s));
    }
    printf("\n");
}

int main() {
    int n, a[MAX_SIZE],i;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements to be sorted:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    bubble_sort(a, n);
    return 0;
}
