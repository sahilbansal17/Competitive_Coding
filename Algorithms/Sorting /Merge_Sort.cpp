#include <bits/stdc++.h>
using namespace std;
#define ll long long

void merge(ll arr[], ll l, ll m, ll r){
    ll i, j, k;
    ll n1 = m - l + 1; //number of elements in first array (left half)
    ll n2 =  r - m; //number of elements in second array (right half)
    ll L[n1], R[n2]; //temporary arrays to store sorted sub-arrays 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0; //Initial index of first subarray
    j = 0; //Initial index of second subarray
    k = l; //Initial index of merged subarray in original array
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){ //picking element from first sub-array
            arr[k++] = L[i++];
        }
        else{ //picking element from second sub-array
            arr[k++] = R[j++];
        }
    }
    while (i < n1){ //picking remaining elements of left sub-array, if any are left
        arr[k++] = L[i++];
    }
    while (j < n2){  //picking remaining elements of right sub-array, if any are left
        arr[k++] = R[j++];
    }
}
 
void mergeSort(ll arr[], ll low, ll high){
    if (low < high){
        ll mid = low+(high-low)/2; //using this concept to avoid overflow in case of large numbers
        mergeSort(arr, low, mid); //sorting left half of array
        mergeSort(arr, mid+1, high); //sorting right half of array
        merge(arr, low, mid, high); //merging both sorted sub-arrays in a sorted fashion
    }
}

void printArray(ll a[], ll n){
    for(ll i=0;i<n;i++)
     printf("%lld ",a[i]);
    printf("\n");
}
 
int main()
{
    ll n;
    scanf("%lld",&n);
    ll arr[n];
    for(ll i=0;i<n;i++)
     scanf("%lld",&arr[i]);
    printf("Entered elements :\n");
    printArray(arr,n);
    mergeSort(arr, 0,n-1); //function to sort array in ascending order using merge sort
    printf("\nSorted array:\n");
    printArray(arr,n);
    return 0;
}

//Time Complexity : O(nlogn)
//Auxiliary Space Complexity : O(n)
