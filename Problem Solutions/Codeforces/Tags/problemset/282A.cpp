#include<bits/stdc++.h>
using namespace std;

int main(void){
	int n, x = 0;
	cin>>n;
	while(n --){
		string s;
		int add = 0, subtract = 0;
		cin>>s;
		for(int i = 0; i < 3; i ++){
			if(s[i] == '+'){
				add = 1;
				break;
			}
			else if(s[i] == '-'){
				subtract = 1;
				break;
			}
		}
		if(add)
			x++;
		if(subtract)
			x--;
	}
	cout<<x;
	return 0;
}