//Name : Shivam Singhal
//Email ID : shivamsinghal0610@gmail.com

#include <bits/stdc++.h>
using namespace std;
 
void countSort(long arr[],long n){
    long l = 0;
    for(long i=0; i<n ;i++){
        //finding largest element to hash
        if(arr[i]>l)
            l = arr[i]; 
    }
    //initialising count of each element present in original array to 0
    long count[l+1] = {0}; 
    //storing frequency of each element using hashing
    for(long i = 0; i<n ; i++)
        count[arr[i]]++; 
    //counter to keep track of position in original array
    long c = 0; 
    for(long i=0; i<=l ;i++){
        //signifies that element i is present in original array
        if(count[i]>0){ 
            while(count[i]!=0){ 
                //overwriting onto original array as many times as element is present
                arr[c++] = i; 
                count[i]--;
            }
        }
    }
}
 
void printArray(long arr[],long n){
    for(long i=0; i<n ;i++)
        printf("%lld ",arr[i]);
    printf("\n");
}

int main(){
    long n;
    printf("Please enter the number of elements."); 
    scanf("%lld",&n);
    printf("\nPlease enter elements to be sorted.\n");
    long arr[n];
    //make sure that the maximum element is lesser than the maximum number of elements an array can hold
    for(long i=0; i<n ;i++)
        scanf("%lld",&arr[i]); 
    printf("Entered elements:\n");
    printArray(arr,n);
    //function to sort elements in ascending order using counting sort technique 
    countSort(arr,n); 
    printf("Sorted array:\n");
    printArray(arr,n);
    return 0;
}

//Time Complexity : O(max). Its more accurately the max of array size and the max element in the array.
//Auxiliary Space Complexity : O(max)