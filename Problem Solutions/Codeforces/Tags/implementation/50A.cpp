#include<bits/stdc++.h>
using namespace std;

int main(void){
	int m,n;
	cin>>m>>n;
	int dominoes = 0;
	if(n >= 2){
		dominoes = m*(n/2) + ((n - 2*(n/2)) * m)/2;
	}
	else{
		dominoes = m/2;
	}
	cout<<dominoes;
}