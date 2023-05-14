#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int low;
    int high;
} stack_data;

stack_data stack[MAX_STACK_SIZE];
int top = -1;

void push(int low, int high) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top].low = low;
    stack[top].high = high;
}

stack_data pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int part(int a[], int low, int high)
{
    int fix = a[low];
    int i = low - 1, j = high + 1;

    while (1) {

        do {
            i++;
        } while (a[i] < fix);

        do {
            j--;
        } while (a[j] > fix);

        if (i >= j)
            return j;

        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int part_r(int a[], int low, int high)
{
    srand(time(0));
    int random = low + rand() % (high - low);

    int temp = a[random];
    a[random] = a[low];
    a[low] = temp;

    return part(a, low, high);
}

void quickSort(int a[], int low, int high)
{
    push(low, high);
    while (top >= 0) {
        stack_data data = pop();
        low = data.low;
        high = data.high;
        if (low < high) {
            int pi = part_r(a, low, high);
            push(low, pi);
            push(pi + 1, high);
        }
    }
}

void printarray(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[6],i ;
    printf("enter elements \n");
    for(i=0;i<6;i++)
    {
        scanf("%d",&a[i]);
    }
    quickSort(a, 0, 6 - 1);
    printf("Sorted aay: \n");
    printarray(a, 6);
    return 0;
}
