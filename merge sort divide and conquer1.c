#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int x, int m, int r)
{
    int i, j, k;
    int n1 = m - x + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[x + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = x;
    while (i < n1 && j < n2)
        {
        if (L[i] <= R[j])
         {
            arr[k] = L[i];
            i++;
        }
        else
         {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
        {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
        {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int h)
{
    if (l < h)
        {

        int m = l + (h - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, h);

        merge(arr, l, m, h);
    }
}
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };


    printf("Given array is \n");
    printArray(arr, 6);
    mergeSort(arr, 0, 5);
    printf("\nSorted array is \n");
    printArray(arr, 6);
    return 0;
}