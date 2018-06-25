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
void swap(int * x, int * y) {
  int temp = * x; * x = * y; * y = temp;
}

// A function to implement bubble sort
void Sort(int arr[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
   
    for (j = 0; j < n - i - 1; j++)
      if (arr[j] > arr[j + 1])
        swap( & arr[j], & arr[j + 1]);
  }
}
int main() {
  int array[100];
  int size, value;
  printf("Enter the size of the array : \n");
  scanf("%d", & size);
  printf("Enter the values : \n");
  for (int i = 0; i < size; i++) {
    scanf("%d", & array[i]);
  }
  
  Sort(array, size);//Array sorted so as to properly implement binary search. 
  
  printf("Enter the value to search : \n");
  scanf("%d", & value);
  
  int position = binarysearch(value, 0, size - 1, array);
  printf("Sorted Array : \n");
  for (int i = 0; i < size; i++)
    printf("%d ", array[i]); //Printing the sorted array for reference.
  printf("\n");
  if (position != -1)
    printf("Value %d found at position %d (In sorted array)\n", value, position + 1);
  else
    printf("Value not found \n");
}
