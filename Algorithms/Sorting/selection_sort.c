#include <stdio.h>

void selectionSort(long arr[], long n){
    long min_index, t;
    for(long i = 0; i <(n-1); i++){
        min_index = i;
        for (long j = i+1; j < n; j++){
            //finding smallest elememt wrt to ith element 
            if (arr[j] < arr[min_index]) 
                min_index = j;
        }
        //swapping elements keeping ith element as pivot
        t = arr[min_index]; 
        arr[min_index] = arr[i];
        arr[i] = t;
    }
}

void printArray(long arr[], long n){
    for (long i=0; i<n; i++)
        printf("%ld ", arr[i]);
    printf("\n");
}

int main()
{
	long n;
    printf("Please enter the number of elements: \n"); 
    scanf("%ld",&n);
    long arr[n];
    printf("\nPlease enter elements to be sorted.\n");
    for(long i=0; i<n ;i++)
      scanf("%ld",&arr[i]);
    printf("Entered elements:\n");
    printArray(arr,n);
    //function to sort elements in ascending order using selection sort
    selectionSort(arr, n); 
    printf("Sorted array: \n");
    printArray(arr, n);
	return 0;
}

