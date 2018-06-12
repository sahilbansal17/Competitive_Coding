#include <iostream>
using namespace std;
int mod(int,int);//modular function
int main() {
	//will be using modular exponentiation (check wikipedia for details over the algo)
	int t;cin>>t;
	while(t--){
	    int a,b;cin>>a>>b;//we need to find last digit of a^b
	    cout<<mod(a,b);
	    cout<<endl;
	}
	return 0;
}
int mod(int a,int b){
    if(b==0)//power is 0
        return 1;
    else if(b%2==0){//power is even
        int y = mod(a,b/2);
        return (y*y)%10;
    }
    else{//power is odd
        return ((a%10)*(mod(a,b-1)%10))%10;
    }
}
