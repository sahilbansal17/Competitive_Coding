#include<bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int count = 0;
	for(int i = 0; i < n; i ++){
		if(s[i] == s[i+1])
			count ++;
	}
	cout<<count;
	return 0;
}	