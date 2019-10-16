#include<stdio.h>
#include<stdlib.h>

void bubbleSort(long arr[], long n)
{
	long i, j;
  int flag = 0;
  for(i=0; i<(n-1); i++){
    flag = 0;
    for(j=0; j<(n-i-1) ;j++)
    {
      if(arr[j]>arr[j+1]){
        long t = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = t;
        flag = 1;
      }
    }
    // exits if there are no more swaps 
    if(flag==0) 
      break;
  }
}

void printArray(long arr[],long size){
	long i;
    for(i=0; i<size; i++)
      printf("%ld ", arr[i]);
    printf("\n");
}

int main()
{
	long n;
    printf("Please enter the number of elements."); 
    scanf("%ld",&n);
    long arr[n];
    printf("\nPlease enter elements to be sorted.\n");
    for(long i=0; i<n ;i++)
      scanf("%ld",&arr[i]);
    printf("Entered elements:\n");
    printArray(arr,n);
    //function to sort elements in ascending order using bubble sort
    bubbleSort(arr, n); 
    printf("Sorted array: \n");
    printArray(arr, n);
	return 0;
}

// Time Complexity -
//   Worst Case : O(n^2). 
//   Average Case : O(n^2). 
//   Best Case : O(n). 
// Auxiliary Space Complexity - O(1).
