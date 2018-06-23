#include<bits/stdc++.h>
using namespace std;
#define ll long long //using macro definition (directive) to simplify code
 
void selectionSort(ll arr[], ll n){
    ll min_index;
    for(ll i = 0; i <(n-1); i++){
        min_index = i;
        for (ll j = i+1; j < n; j++){
          if (arr[j] < arr[min_index]) //finding smallest elememt wrt to ith element 
            min_index = j;
        }
        ll t=arr[min_index]; //swapping elements keeping ith element as pivot
        arr[min_index]=arr[i];
        arr[i]=t;
    }
}
 
void printArray(ll arr[], ll n){
    for (ll i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main(){
    ll n;
    scanf("%lld",&n);
    ll arr[n]; //declaring array of given size
    for(ll i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    printf("Entered elements: \n");
    printArray(arr, n);
    selectionSort(arr, n); //function to sort elements in ascending order
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

//Time Complexity : O(n^2)
//Auxiliary Space Complexity : O(1)