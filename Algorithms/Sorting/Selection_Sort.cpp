//Name : Shivam Singhal
//Email ID : shivamsinghal0610@gmail.com

#include<bits/stdc++.h>
using namespace std;
 
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
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main(){
    long n;
    printf("Please enter the number of elements."); 
    scanf("%lld",&n);
    long arr[n];
    printf("\nPlease enter elements to be sorted.\n");
    for(long i=0; i<n ;i++)
        scanf("%lld",&arr[i]);
    printf("Entered elements: \n");
    printArray(arr, n);
    //function to sort elements in ascending order
    selectionSort(arr, n); 
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

//Time Complexity : O(n^2). Same for all cases as we use 2 nested loops of n runtime each.
//Auxiliary Space Complexity : O(1). We make use of an extra variable "min_index" and temp variable t.
