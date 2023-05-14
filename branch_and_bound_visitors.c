#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N 10

int n;
int cost[MAX_N][MAX_N];
int visited[MAX_N];
int best_cost = INT_MAX;

void branch_and_bound(int current_cost, int current_node, int num_visited)
 {
     int i;
    if (current_cost >= best_cost)
        {
        return;
    }
    if (num_visited == n)
        {
        best_cost = current_cost;
        return;
    }
    for ( i = 0; i < n; i++)
        {
        if (!visited[i])
        {
            visited[i] = 1;
            branch_and_bound(current_cost + cost[current_node][i], i, num_visited + 1);
            visited[i] = 0;
        }
    }
}

int main()
 {
    int i,j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    visited[0] = 1;
    branch_and_bound(0, 0, 1);
    printf("The minimum cost is %d\n", best_cost);
    return 0;
}

