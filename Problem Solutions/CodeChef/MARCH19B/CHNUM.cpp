#include <iostream>
using namespace std;
#include<bits/stdc++.h>
int main() {
    int t;
    cin >>t;
    for (int l=0;l<t;l++){
        int n;
        cin >>n;
        long long a[n];
        int pos=0,neg=0,zero=0;
        for (int i=0;i<n;i++){
            cin >> a[i];
            if(a[i]>0)
            pos++;
            else if(a[i]==0)
            zero++;
            else neg++;
        }
    if(pos>neg){
        cout<< pos+zero<< " ";
        if(zero==0 && neg>0)
        cout << neg;
        if(zero==0 && neg==0)
        cout <<pos;
        if(zero>0)
        cout << "1";
    }
    else{
        cout<< neg+zero<< " ";
        if(zero==0 && pos>0)
        cout << pos;
        if(zero==0 && pos==0)
        cout <<neg;
        if(zero>0)
        cout << "1";
    }
        cout << endl;
    }
    return 0;
}
