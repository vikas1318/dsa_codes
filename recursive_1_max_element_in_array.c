#include<stdio.h>
#define MAX 100
int n;
int maximum(int arr[])
{
    static int i=0,max =-9999;
    if(i < n)
    {
         if(max<arr[i])
           max=arr[i];
      i++;
      maximum(arr);
    }
    return max;
}
int main()
{
    int arr[MAX],max,i;
      printf(" give number of elements of array :");
       scanf("%d",&n);

       printf(" elements in the array :\n",n);
       for(i=0;i<n;i++)
        {
	      scanf("%d",&arr[i]);
	    }
    max=maximum(arr);
    printf(" Largest element of the array is: %d\n",max);
    return 0;
}
