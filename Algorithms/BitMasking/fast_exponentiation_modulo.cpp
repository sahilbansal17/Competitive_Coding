//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to find exponential modulo using bitmasking
#include <iostream>
#define ll long long

using namespace std;

//fastModExp() function returns the exponential modulo 
//return a^b % m
ll fastModExp(ll a,ll b,ll m){
	//initializithe res to 1 
    ll res =1;
    
    //iterating over the b to its bits
    while(b>0){
    	//if the bit is 1 than multiply it by a and taking modulo 
        if(b&1){
            res = (res*a)%m;
        }
        //updating the bits and value of a to its square
        a = (a*a)%m;
        b= b>>1;
    }
    return res%m;
}


int main()
{
	cout<<"Enter a,b and m respectively : ";
	ll a,b,m;
	cin>>a>>b>>m;
    cout<<a<<" raise to power "<<b<<" Modulo "<<m<<" is : "<<fastModExp(a,b,m);

    return 0;
}
