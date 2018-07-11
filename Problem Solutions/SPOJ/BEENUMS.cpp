#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(void){
    int k;cin>>k;
    while(k != -1){
        // the sequence is quite observable as 1 7 19 37 61 ..., Nth term will be 3*n^2 - 3*n + 1
        float n;
        n = ( 1 - sqrt( 1 + ((4*(k-1))/3) ) )/2;//finding the value of n
        if(n - int(n))
            cout<<"N"<<endl;
        else
            cout<<"Y"<<endl;
        cin>>k;
    }
    return 0;
}