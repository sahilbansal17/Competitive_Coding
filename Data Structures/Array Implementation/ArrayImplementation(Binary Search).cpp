//A programme for basic Array Implmentation - Binary Search. 
#include <stdio.h>

  int binarysearch(int value, int left, int right, int array[]) {
    //Function which performs a binary search in a sorted array and returns the index.
    if (right >= left) {
      int mid = left + (right - left) / 2;

      if (array[mid] == value)
        return mid; //Mid value is the required value

      if (array[mid] > value)
        return binarysearch(value, left, mid - 1, array); //Not found, as array is sorted, item is present in left.

      if (array[mid] < value)
        return binarysearch(value, mid + 1, right, array); //Not found, as array is sorted, item is present in right.

    }

    return -1; //Returns -1 if not found
  }
int main() {
  int array[100];
  int size, value;
  printf("Enter the size of the sorted array : \n");
  scanf("%d", & size);
  printf("Enter the values in a sorted increasing manner : \n");
  for (int i = 0; i < size; i++) {
    scanf("%d", & array[i]);
  }
  printf("Enter the value to search : \n");
  scanf("%d", & value);
  int position = binarysearch(value, 0, size - 1, array);
  if (position != -1)
    printf("Value %d found at position %d \n", value, position + 1);
  else
    printf("Value not found \n");
}
