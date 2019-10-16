#include<stdio.h>

void countSort(long arr[], long n) {
	long i, largest = 0, output[n];
	for (i = 0; i < n; ++i) {
		// finding the largest element for hashing
		if (arr[i] > largest) largest = arr[i];
	}
	
	long count[largest + 1];
	for (i = 0; i < largest+1; ++i) 
		count[i] = 0; // initialising count with 0

	// Store count of each character
	for (i = 0; i < n; ++i) 
		++count[arr[i]];

	for (i = 1; i < largest+1; ++i) 
        count[i] += count[i-1];

    // Build the output array
    for (i = 0; i < n; ++i) 
    { 
        output[count[arr[i]]-1] = arr[i]; 
        --count[arr[i]]; 
    } 

    // copy the result to arr 
    for (i = 0; i < n; ++i) 
        arr[i] = output[i]; 

} 

void printArray(long arr[],long size){
	long i;
    for(i=0; i<size; i++)
      printf("%ld ", arr[i]);
    printf("\n");
}

int main() {
	
	long n, i;
	printf("Enter the number of element in array: \n");
	scanf("%ld", &n);
	printf("Enter the array elements : \n"); 
	long arr[n];
	for (i = 0; i < n; ++i) 
		scanf("%ld", &arr[i]);

	printf("Original Array: \n");
	printArray(arr,n);
	//function to sort elements in ascending order using counting sort
    countSort(arr, n); 
    printf("Sorted array: \n");
    printArray(arr, n); 
	return 0;
}


// Time Complexity -
//   O(n+k) where n is the number of elements in input array 
//   and k is the range of input.. 
// Auxiliary Space Complexity - O(n+k).