#include<bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	string word = "hello";
	int count = 0, j = 0;
	for(int i = 0; i < s.size(); i ++){
		if(s[i] == word[j]){
			j++;
			count++;
		}
	}
	if(count == 5)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}