#include <bits/stdc++.h>
// Author: @NavonilDas
// Compile in C++ 14
using namespace std;

/**
 * Given an array such every elements repeats itself twice except one element
 * we have to find the element which is not repeated.
 * we know that  ( A xor A = 0 ) and ( 0 xor A = A )
 * so if we xor all the elements in the array we will be left with the element we need.
 * example: 10 5 10 => (10 xor 10) xor 5 => 0 xor 5 => 5
 * alternative methods to solve this problem can be by using map,by using nested loops
 * */
int getUnique(vector<int> ar){
    if(ar.size() == 0)
        throw "No Elements in Array";
    int element = 0;
    // Iterate through each item in array
    for(int item:ar)
        element = element ^ item;
    return element;
}


int main(){
    vector<int> ar = {10,5,10,50,100,50,5};
    
    cout<<"Unique Element is : "<<getUnique(ar)<<endl;

    return 0;
}