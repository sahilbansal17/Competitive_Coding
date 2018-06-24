#include <bits/stdc++.h>
using namespace std;
#define ll long long //using macro definition (directive) 

void bubbleSort(ll arr[], ll n)
{
  ll flag=0;
  for(ll i=0;i<(n-1);i++){
    flag=0;
    for(ll j=0;j<(n-i-1);j++)
    {
      if(arr[j]>arr[j+1]){
        ll t=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=t;
        flag=1;
      }
    }
    if(flag==0) //checks if all elements are sorted or not
     break;
  }
}
 
void printArray(ll arr[],ll size){
    for(ll i=0; i < size; i++)
      printf("%lld ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main(){
    ll n;
    scanf("%lld",&n);
    ll arr[n];
    for(ll i=0;i<n;i++)
      scanf("%lld",&arr[i]);
    printf("Entered elements:\n");
    printArray(arr,n);
    bubbleSort(arr, n); //function to sort elements in ascending order using bubble sort
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}

//Time Complexity : O(n^2)
//Auxiliary Space Complexity : O(1)