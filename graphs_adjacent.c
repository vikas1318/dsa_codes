// Adjacency Matrix representation in C
#include <stdio.h>
#define V 4
// Initialize the matrix to zero
void init(int arr[][V])
{
  int i, j;
  for (i = 0; i < V; i++)
  {
      for (j = 0; j < V; j++)
      {
                arr[i][j] = 0;
      }
  }
}

// Add edges
void addEdge(int arr[][V], int i, int j)
{
  arr[i][j] = 1;
  arr[j][i] = 1;
}

// Print the matrix
void printAdjMatrix(int arr[][V],FILE *fp1)
{
  int i, j;
  for (i = 0; i < V; i++)
    {
    printf("%d: ", i);
    fprintf(fp1,"%d :",i);
    for (j = 0; j < V; j++)
    {
      printf("%d ", arr[i][j]);
      fprintf(fp1,"%d ",arr[i][j]);
    }
    fprintf(fp1,"\n");
    printf("\n");
  }
}

int main()
 {
  int adjMatrix[V][V];
   FILE *fp1;
   fp1=fopen("adjacent_matrix.txt","w");
  init(adjMatrix);
  addEdge(adjMatrix, 0, 1);
  addEdge(adjMatrix, 0, 2);
  addEdge(adjMatrix, 1, 2);
  addEdge(adjMatrix, 2, 0);
  addEdge(adjMatrix, 2, 3);

  printAdjMatrix(adjMatrix,fp1);

  return 0;
}
