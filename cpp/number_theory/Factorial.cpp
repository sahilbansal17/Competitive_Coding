#include<iostream>
using namespace std;

template<class T>
T factorial(T n){
	if(n == 0 || n == 1)return 1;
	
	return n*factorial(n-1);
	}
	
int main(){
	cout<<factorial(5)<<endl;
	}
