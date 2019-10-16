#include<stdio.h>

void insertionSort(long v[], int n){
    // mechanism for insertion sort
    long i;
    for(i = 1;i < n;i++){
        long temp = v[i],j;
        for(j = i-1; j >=0; j--){
            if(v[j] > temp)
                v[j+1] = v[j];
            else
                break;
        }
        v[j+1] = temp;
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
    printf("Please enter the number of elements: \n"); 
    scanf("%ld",&n);
    long arr[n];
    printf("\nPlease enter elements to be sorted: \n");
    for(long i=0; i<n ;i++)
      scanf("%ld",&arr[i]);
    printf("Entered elements:\n");
    printArray(arr,n);
    //function to sort elements in ascending order using insertion sort
    insertionSort(arr, n); 
    printf("Sorted array: \n");
    printArray(arr, n);
	return 0;
}