#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define MAX_EDGES 100

typedef struct {
    int start, end, weight;
} Edge;

typedef struct {
    Edge edges[MAX_EDGES];
    int size;
} Graph;

typedef struct {
    int data[MAX_VERTICES];
    int front, rear;
} Queue;

void createGraph(Graph *G) {
    G->size = 0;
}

void addEdge(Graph *G, int start, int end, int weight) {
    G->edges[G->size].start = start;
    G->edges[G->size].end = end;
    G->edges[G->size].weight = weight;
    G->size++;
}

void enqueue(Queue *q, int value) {
    q->data[q->rear] = value;
    q->rear++;
}

int dequeue(Queue *q) {
    int value = q->data[q->front];
    q->front++;
    return value;
}

void sortEdges(Graph *G) {
    int i, j;
    Edge temp;

    for(i = 0; i < G->size - 1; i++) {
        for(j = i+1; j < G->size; j++) {
            if(G->edges[i].weight > G->edges[j].weight) {
                temp = G->edges[i];
                G->edges[i] = G->edges[j];
                G->edges[j] = temp;
            }
        }
    }
}

int findSet(int parent[], int vertex) {
    if(parent[vertex] == -1) {
        return vertex;
    }
    return findSet(parent, parent[vertex]);
}

void unionSet(int parent[], int start, int end) {
    parent[start] = end;
}

void kruskalMST(Graph *G) {
    int parent[MAX_VERTICES], i, j, start, end, totalWeight = 0;
    Queue q;

    createGraph(G);
    sortEdges(G);

    for(i = 0; i < MAX_VERTICES; i++) {
        parent[i] = -1;
    }

    q.front = q.rear = 0;

    for(i = 0; i < G->size; i++) {
        start = findSet(parent, G->edges[i].start);
        end = findSet(parent, G->edges[i].end);

        if(start != end) {
            enqueue(&q, i);
            totalWeight += G->edges[i].weight;
            unionSet(parent, start, end);
        }
    }

    printf("Edges in the MST:\n");
    for(i = 0; i < q.rear; i++) {
        printf("(%d, %d) ", G->edges[q.data[i]].start, G->edges[q.data[i]].end);
    }

    printf("\nTotal weight of the MST: %d\n", totalWeight);
}

int main() {
    Graph G;
    int i, vertices, edges, start, end, weight;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    for(i = 0; i < edges; i++)
        {
        printf("Enter the start vertex, end vertex and weight of edge %d: ", i+1);
        scanf("%d%d%d", &start, &end, &weight);
        addEdge(&G, start, end, weight);
    }
}

