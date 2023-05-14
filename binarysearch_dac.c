#include <stdio.h>

int bS(int array[], int x, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;
    if (array[mid] == x)
      return mid;
    if (array[mid] > x)
      return bS(array, x, low, mid - 1);
    return bS(array, x, mid + 1, high);
  }

  return -1;
}

int main(void) {
  int array[7] = {3, 4, 5, 6, 7, 8, 9},x;
  printf("enter the number to be searched\n");
  scanf("%d",&x);
  int result = bS(array, x, 0, 6);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
}
