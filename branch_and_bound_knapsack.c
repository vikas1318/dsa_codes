#include <stdio.h>

#define MAX_N 100
#define MAX_W 1000

typedef struct {
    int value;
    int weight;
} Item;

Item items[MAX_N];
int n, W;
int bestvalue = 0;
int a[MAX_N];
int max_weight[MAX_N] = {0};

void branch(int i, int value, int weight) {
    int j;
    if (weight > W) {
        return;
    }
    if (i == n) {
        if (value > bestvalue) {
            bestvalue = value;
            for (j = 0; j < n; j++) {
                a[j] = max_weight[j];
            }
        }
        return;
    }
    int bound = value;
    j = i;
    while (j < n && weight + items[j].weight <= W) {
        bound += items[j].value;
        weight += items[j].weight;
        max_weight[j] = 1;
        j++;
    }
    if (j < n) {
        bound += (W - weight) * items[j].value / items[j].weight;
    }
    if (bound <= bestvalue) {
        return;
    }
    branch(i+1, value, weight);
    max_weight[i] = 1;
    branch(i+1, value + items[i].value, weight + items[i].weight);
    max_weight[i] = 0;
}

int main() {
    int i;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Enter the value and weight of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }
    branch(0, 0, 0);
    printf("The optimal value is %d\n", bestvalue);
    printf("The following items are a:\n");
    for (i = 0; i < n; i++) {
        if (a[i]) {
            printf("%d ", i+1);
        }
    }
    printf("\n");
    return 0;
}
