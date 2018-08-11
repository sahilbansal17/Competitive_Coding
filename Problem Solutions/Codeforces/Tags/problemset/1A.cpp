#include<bits/stdc++.h>
using namespace std;

int main(void){
	long long int n, m, a, row;
	cin>>n>>m>>a;
	long long int rows, cols;
	if(n % a == 0){
		rows = n/a;
	}
	else{
		rows = n/a + 1;
	}
	if(m % a == 0){
		cols = m/a;
	}
	else{
		cols = m/a + 1;
	}
	cout<<rows*cols;
	return 0;
}