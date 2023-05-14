#include<stdio.h>
#define MAX 10
void multiply(int [MAX][MAX],int [MAX][MAX]);
int r1,c1,r2,c2;
int arr[MAX][MAX];
int sum,i=0,j=0,k=0;
int main()
{
    int arr1[MAX][MAX],arr2[MAX][MAX],i,j,k;
    printf("rows for the first matrix : ");
    scanf("%d",&r1);
    printf("columns for the first matrix : ");
    scanf("%d",&c1);

    printf("rows for the second matrix : ");
    scanf("%d",&r2);
    printf("columns for the second matrix : ");
    scanf("%d",&c2);
    if(c1!=r2)
    {
         printf("\n not possible \n");
    }
    else
    {
      printf("\n give elements for the first matrix :\n");
      for(i=0;i<r1;i++)
        {
      for(j=0;j<c1;j++)
        {
	  	   printf(" [%d],[%d] : ",i,j);
           scanf("%d",&arr1[i][j]);
      }
      }
      printf(" give elements for the second matrix :\n");
      for(i=0;i<r2;i++)
        {
      for(j=0;j<c2;j++)
      {
		   printf("[%d],[%d] : ",i,j);
           scanf("%d",&arr2[i][j]);
      }
      }
      printf("\n First matrix elements are : \n");
      for(i=0;i<r1;i++)
      {
      printf("\n");
      for(j=0;j<c1;j++)
      {
           printf(" %d\t",arr1[i][j]);
      }
      }
      printf("\n  Second matrix is : \n");
      for(i=0;i<r2;i++)
      {
      printf("\n");
      for(j=0;j<c2;j++)
      {
           printf(" %d\t",arr2[i][j]);
      }
      }
      multiply(arr1,arr2);
  }
  printf("\n The multiplication of two matrix is : \n");
  for(i=0;i<r1;i++)
  {
      printf("\n");
      for(j=0;j<c2;j++)
      {
           printf(" %d\t",arr[i][j]);
      }
  }
  printf("\n\n");
  return 0;
}
void multiply(int arr1[MAX][MAX],int arr2[MAX][MAX])
{
    if(i<r1)
    {
    if(j<c2)
    {
         if(k<c1)
         {
             sum=sum+arr1[i][k]*arr2[k][j];
             k++;
             multiply(arr1,arr2);
         }
         arr[i][j]=sum;
             sum=0;
             k=0;
             j++;
             multiply(arr1,arr2);
    }
    j=0;
    i++;
    multiply(arr1,arr2);
    }
}
