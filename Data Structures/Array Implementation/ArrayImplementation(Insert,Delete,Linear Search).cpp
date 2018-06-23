//A programme for basic Array Implmentation - Insertion, Deletion, Search (Linear).

#include <stdio.h>

  int linearsearch(int value, int n, int array[]) {
    //Function which performs a linear search and returns the index.
    int p = -1;
    for (int i = 0; i < n; i++) {
      if (value == array[i]) {
        p = i; //Value found in the array
        break;
      }
    }
    return p;
  }
int main() {
  int task = 0, position, n;
  int value;
  int sample_array[1000];
  //Input of sample array
  printf("Enter number of elements in array\n");
  scanf("%d", & n);
  printf("Enter elements\n");

  for (int c = 0; c < n; c++) {
    scanf("%d", & sample_array[c]);
  }

  while (task != 4) {
    //User manual
    printf("Press the index of task to be performed : \n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Search an element(Linear Search)\n");
    printf("4.Exit\n");

    scanf("%d", & task);

    if (task == 1) {
      printf("Enter the value to be inserted :\n");
      scanf("%d", & value);
      printf("Enter the position where you want to insert : \n");
      scanf("%d", & position);
      for (int p = n - 1; p >= position - 1; p--) {
        sample_array[p + 1] = sample_array[p];
      }
      sample_array[position - 1] = value;
      printf("Insertion Successful\n");
      printf("Resultant array is\n");
      n++;
      for (int c = 0; c < n; c++) {
        printf("%d ", sample_array[c]);
      }
      printf("\n");
    }
    if (task == 2) {
      printf("Enter the value to be deleted : \n");
      scanf("%d", & value);
      position = linearsearch(value, n, sample_array);
      printf("Position : %d\n", position);
      for (int i = position; i < n; i++) {
        sample_array[i] = sample_array[i + 1];
      }
      n--;
      printf("Successful !\n");
      printf("Resultant array is\n");
      for (int c = 0; c < n; c++) {
        printf("%d ", sample_array[c]);
      }
      printf("\n");
    }
    if (task == 3) {
      printf("Enter the value to search : \n");
      scanf("%d", & value);

      position = linearsearch(value, n, sample_array);

      if (position != -1)
        printf("Value found at position : %d\n", position + 1);
      else
        printf("Value not found !\n");
    }
  }
}
