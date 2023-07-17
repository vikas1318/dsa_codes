#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

struct node* createNode(int v);

struct Graph {
  int numver;
  int* visited;
  struct node** adjlists;
};

void DFS(struct Graph* graph, int vertex)
{
  struct node* adjList = graph->adjlists[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
  printf("Visited %d \n", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}

struct node* createNode(int v)
 {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

struct Graph* createGraph(int vertices)
 {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numver = vertices;

  graph->adjlists = malloc(vertices * sizeof(struct node*));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjlists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}


void addEdge(struct Graph* graph, int src, int dest)
 {
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjlists[src];
  graph->adjlists[src] = newNode;
  newNode = createNode(src);
  newNode->next = graph->adjlists[dest];
  graph->adjlists[dest] = newNode;
}


void printGraph(struct Graph* graph)
 {
  int v;
  for (v = 0; v < graph->numver; v++) {
    struct node* temp = graph->adjlists[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  struct Graph* graph = createGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);

  printGraph(graph);

  DFS(graph, 2);

  return 0;
}
