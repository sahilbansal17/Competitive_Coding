#include<bits/stdc++.h>
using namespace std;

int main(void){
	string s;
	cin>>s;
	int count = 0;
	int flag = 0;
	for(int i = 0; i < s.size() - 1; i ++){
		if(s[i] == '0' && s[i+1] == '0'){
			count++;
			if(count >= 6){
				flag = 1;
				break;
			}
		}
		else if(s[i] == '1' && s[i+1] == '1'){
			count++;
			if(count >= 6){
				flag = 1;
				break;
			}
		}
		else
			count = 0;
	}
	if(flag == 1){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
	return 0;
}