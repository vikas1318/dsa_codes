// BFS algorithm in C

#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

struct queue {
  int items[SIZE];
  int front;
  int rear;
};

struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printque(struct queue* q);

struct node {
  int vertex;
  struct node* next;
};

struct node* createNode(int);

struct Graph {
  int numvertex;
  struct node** adjlists;
  int* visited;
};
void bfs(struct Graph* graph, int startVertex)
 {
  struct queue* q = createQueue();

  graph->visited[startVertex] = 1;
  enqueue(q, startVertex);

  while (!isEmpty(q))
{
    printque(q);
    int currentVertex = dequeue(q);
    printf("Visited %d\n", currentVertex);

    struct node* temp = graph->adjlists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (graph->visited[adjVertex] == 0)
        {
        graph->visited[adjVertex] = 1;
        enqueue(q, adjVertex);
      }
      temp = temp->next;
    }
  }
}

struct node* createNode(int v)
 {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}


struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numvertex = vertices;

  graph->adjlists = malloc(vertices * sizeof(struct node*));
  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjlists[i] = NULL;
    graph->visited[i] = 0;
  }

  return graph;
}


void addedge(struct Graph* graph, int s, int dest) {

  struct node* newNode = createNode(dest);
  newNode->next = graph->adjlists[s];
  graph->adjlists[s] = newNode;


  newNode = createNode(s);
  newNode->next = graph->adjlists[dest];
  graph->adjlists[dest] = newNode;
}

struct queue* createQueue()
 {
  struct queue* q = malloc(sizeof(struct queue));
  q->front = -1;
  q->rear = -1;
  return q;
}


int isEmpty(struct queue* q)
 {
  if (q->rear == -1)
    return 1;
  else
    return 0;
}


void enqueue(struct queue* q, int value) {
  if (q->rear == SIZE - 1)
    printf("\nQueue is Full!!");
  else {
    if (q->front == -1)
      q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
  }
}


int dequeue(struct queue* q) {
  int item;
  if (isEmpty(q)) {
    printf("Queue is empty");
    item = -1;
  } else {
    item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
      printf("Resetting queue ");
      q->front = q->rear = -1;
    }
  }
  return item;
}

void printque(struct queue* q)
 {
  int i = q->front;
  if (isEmpty(q)) {
    printf("Queue is empty");
  } else {
    printf("\nQueue contains \n");
    for (i = q->front; i < q->rear + 1; i++)
        {
      printf("%d ", q->items[i]);

    }
  }
}

int main() {
  struct Graph* graph = createGraph(6);
  addedge(graph, 0, 1);
  addedge(graph, 0, 2);
  addedge(graph, 1, 2);
  addedge(graph, 1, 4);
  addedge(graph, 1, 3);
  addedge(graph, 2, 4);
  addedge(graph, 3, 4);

  bfs(graph, 0);

  return 0;
}
