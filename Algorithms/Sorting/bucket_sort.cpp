// Name : Anjali Kumari
// Email : LIT2016033@iiitl.ac.in

// This program contains implementation of Bucket Sort Algorithm.

#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>
using namespace std;

#define bucket_size 10

void bucketSort(float arr[], long n)
{  
    vector<float> bucket[bucket_size];
    //we make empty bucket vectors of size bucket_size , vector is choosen instead of
	//2-d array because we can dynamically regulate size of vector.
	
    for(long i=0;i<n;i++)
    {
       long d = arr[i]*n; //Index determination in a bucket.
       bucket[d].push_back(arr[i]);
    }
    for(long i=0;i<bucket_size;i++)
    {
       	sort(bucket[i].begin(),bucket[i].end());
    }
    long j=0,index=0;
    while(j!=bucket_size)
    {
       for(long i=0;i<bucket[j].size();i++)
       {
            arr[index++]=bucket[j][i];
       }
       j++;
    }
}
 
//Function to print the elements of Array
void printArray(float arr[],long arr_length)
{
    for(long i=0; i<arr_length; i++)
    {
      printf("%f ", arr[i]);
    }
    printf("\n");
}

// Driver program to test bucketSort function
int main()
{
    long n;
    printf("Please enter the number of elements in Array."); 
    scanf("%lld",&n);
    float arr[n];
    printf("\nPlease enter the elements of array to be sorted.\n");
    
    for(long i=0; i<n ;i++)
    {
      scanf("%f",&arr[i]);
    }
    
    printf("The entered elements are :\n");
    printArray(arr,n);
    
    //function to sort elements in ascending order using Bucket sort
    bucketSort(arr, n); 
    printf("The sorted array is: \n");
    printArray(arr, n);
    return 0;
}

//Bucket sort assumes that the input is drawn from a uniform distribution.
//Sample Input : 6 0.2324 0.9876 0.2345 0.4456 0.7878 0.8672
//Output : 0.2324 0.2345 0.4456 0.7878 0.8672 0.9876 
//Space Complexity : O(n+k) 
//Average Case and Best Case Time Complexity : O(n+k)
//Worst Case Time Complexity : O(n^2) 
//n is the number of elements to be sorted and k is the number of buckets
//Bucket Sort is a sorting method that subdivides the given data into various buckets .
//Bucket sort’s best case occurs when the data being sorted can be distributed between 
//the buckets perfectly. If the values are sparsely allocated over the possible value range, 
//a larger bucket size is better since the buckets will likely be more evenly distributed.
//Bucket sort performs at its worst when all elements are allocated to the same bucket.
//I have used inbuilt sort in for all buckets.It has time complexity of O(n log n).
//Insertion sort can also be used for sorting these buckets ,but if single bucket will 
//contain all elements then Insertion Sort will be a bad choice .
