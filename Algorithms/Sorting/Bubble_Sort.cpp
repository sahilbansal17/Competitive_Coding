//Name : Shivam Singhal
//Email ID : shivamsinghal0610@gmail.com

#include <bits/stdc++.h>
using namespace std;

void bubbleSort(long arr[], long n)
{
  long flag = 0;
  for(long i=0; i<(n-1); i++){
    flag = 0;
    for(long j=0; j<(n-i-1) ;j++)
    {
      if(arr[j]>arr[j+1]){
        long t = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = t;
        flag = 1;
      }
    }
    //checks if all elements are sorted or not
    if(flag==0) 
      break;
  }
}
 
void printArray(long arr[],long size){
    for(long i=0; i<size; i++)
      printf("%lld ", arr[i]);
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
    printf("Entered elements:\n");
    printArray(arr,n);
    //function to sort elements in ascending order using bubble sort
    bubbleSort(arr, n); 
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

/*
Time Complexity -
  Worst Case : O(n^2). 
  Average Case : O(n^2). 
  Best Case : O(n). 

Worst case is O(n^2) because there might be a case (say, when array is reverse sorted) 
when both the loops of n runtime execute completely. 

Best case is O(n) because when the array is already sorted in required order, the inner 
loop will just execute n times and flag will remain as 0 indicating that the array is already
sorted and outer loop will break because of applied condition.

In average case calculation, we usually consider all possible cases. We know that the worst case
complexity is O(n^2) which will included in average case calculation as well, so that becomes the dominant term.

Auxiliary Space Complexity - O(1). We use just one extra variable. 
*/