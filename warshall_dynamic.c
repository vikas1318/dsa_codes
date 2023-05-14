#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void warshalls(int a[50][50],int n)
{
    int k,i,j;
  for(k=0;k<n;k++)
  {
    for( i=0;i<n;i++)
    {
        for( j=0;j<n;j++)
        {
            if(a[i][k]==1 &&a[k][j]==1)
            {
                a[i][j]=1;
            }
        }
    }
  }
}
int main()
{
    int a[50][50],n,i,j;
    printf("enter n value:\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    warshalls(a,n);
    printf("all pair shortest path:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
