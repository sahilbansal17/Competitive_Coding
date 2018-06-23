#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
void countSort(ll arr[],ll n){
    ll l=0;
    for(ll i=0;i<n;i++){
        if(arr[i]>l)
            l=arr[i]; //finding largest element to hash
    }
    ll count[l+1]={0}; //initialising count of each element present in original array to 0
    for(ll i = 0;i<n; i++)
        count[arr[i]]++; //storing frequency of each element using hashing
    ll c=0; //counter to keep track of position in original array
    for(ll i=0;i<=l;i++){
        if(count[i]>0){ //signifies that element i is present in original array
            while(count[i]!=0){ 
                arr[c++]=i; //overwriting onto original array as many times as element is present
                count[i]--;
            }
        }
    }
}
 
void printArray(ll arr[],ll n){
    for(ll i=0;i<n;i++)
        printf("%lld ",arr[i]);
    printf("\n");
}

int main(){
    ll n;
    scanf("%lld",&n);
    ll arr[n];
    for(ll i=0;i<n;i++)
        scanf("%lld",&arr[i]); //make sure that the maximum element is lesser than the maximum number of elements an array can hold
    printf("Entered elements:\n");
    printArray(arr,n);
    countSort(arr,n); //function to sort elements in ascending order using counting sort technique 
    printf("Sorted array:\n");
    printArray(arr,n);
    return 0;
}