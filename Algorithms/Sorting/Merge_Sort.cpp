//Name : Shivam Singhal
//Email ID : shivamsinghal0610@gmail.com

#include <bits/stdc++.h>
using namespace std;

void merge(long arr[], long l, long m, long r){
    long i, j, k;  
    //number of elements in first array (left half)
    long n1 = m - l + 1; 
    //number of elements in second array (right half)
    long n2 =  r - m; 
    //temporary arrays to store sorted sub-arrays 
    long L[n1], R[n2]; 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    //Initial index of first subarray
    i = 0; 
    //Initial index of second subarray
    j = 0; 
    //Initial index of merged subarray in original array
    k = l; 
    while (i < n1 && j < n2){
        //picking element from first sub-array
        if (L[i] <= R[j]){ 
            arr[k++] = L[i++];
        }
        //picking element from second sub-array
        else{ 
            arr[k++] = R[j++];
        }
    }
    //picking remaining elements of left sub-array, if any are left
    while (i < n1){ 
        arr[k++] = L[i++];
    }
    //picking remaining elements of right sub-array, if any are left
    while (j < n2){  
        arr[k++] = R[j++];
    }
}
 
void mergeSort(long arr[], long low, long high){
    if (low < high){
        //using this concept to avoid overflow in case of large numbers
        long mid = low + ((high-low)/2); 
        //sorting left half of array
        mergeSort(arr, low, mid); 
        //sorting right half of array
        mergeSort(arr, mid+1, high);
        //merging both sorted sub-arrays in a sorted fashion 
        merge(arr, low, mid, high); 
    }
}

void printArray(long a[], long n){
    for(long i=0; i<n ;i++)
     printf("%lld ",a[i]);
    printf("\n");
}
 
int main()
{
    long n;
    printf("Please enter the number of elements."); 
    scanf("%lld",&n);
    long arr[n];
    printf("\nPlease enter elements to be sorted.\n");
    for(long i=0; i<n ;i++)
     scanf("%lld",&arr[i]);
    printf("Entered elements :\n");
    printArray(arr,n);
    //function to sort array in ascending order using merge sort
    mergeSort(arr, 0,n-1); 
    printf("\nSorted array:\n");
    printArray(arr,n);
    return 0;
}

/*
Time Complexity : O(nlogn). 
The entire input is iterated over. This occurs O(log(n)) times (the input can only be halved O(log(n)) times). n items iterated log(n) times gives O(n log(n)).

Auxiliary Space Complexity : O(n). We use an extra array of n size. 
*/
