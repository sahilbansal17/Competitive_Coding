#include<bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		if(s.size() > 10){
			cout<<s[0]<<s.size()-2<<s[s.size()-1]<<endl;
		}
		else{
			cout<<s<<endl;
		}
	}
	return 0;
}