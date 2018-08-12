#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	int upper = 1, firstletter = 0, n = s.size();
	if(n > 1){
		for(int i = 1; i < n; i ++){
			if(!isupper(s[i])){
				upper = 0;//not all upper case
			}
		}
		if(isupper(s[0])){
			firstletter = 1;//first letter is upper case too
		}
		else{
			firstletter = 0;//it's not
		}
		if(firstletter == 1 && upper == 1){
			for(int i = 0; i < n; i ++){
				s[i] = tolower(s[i]);
			}
		}
		else if(firstletter == 0 && upper == 1){
			for(int i = 1; i < n; i ++){
				s[i] = tolower(s[i]);
			}
			s[0] = toupper(s[0]);
		}
		else if(upper == 0){
			;
		}
		else ;
	}
	else{
		if(!isupper(s[0])){
			s[0] = toupper(s[0]);
		}
		else{
			s[0] = tolower(s[0]);
		}
	}
	cout<<s;
	return 0;
}