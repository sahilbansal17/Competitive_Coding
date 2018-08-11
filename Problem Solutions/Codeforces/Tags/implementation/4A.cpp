#include<bits/stdc++.h>
using namespace std;

int main(void){
	int w;
	cin>>w;
	if(w > 2){
		if(w % 2 == 0){
			cout<<"YES";
		}
		else{
			cout<<"NO";
		}
	}
	else{
		cout<<"NO";
	}
}