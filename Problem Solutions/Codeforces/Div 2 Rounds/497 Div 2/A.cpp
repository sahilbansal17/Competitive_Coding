#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	#endif

	string s;
	cin >> s;

	int len = s.length();

	bool res = true;

	for(int i = 0; i < len - 1; i ++){
		if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' && s[i] != 'n'){
			if(s[i + 1] != 'a' && s[i + 1] != 'e' && s[i + 1] != 'o' && s[i + 1] != 'u' && s[i + 1] != 'i'){
				res = false;
				break;
			}
		}
	}
	if(s[len - 1] != 'a' && s[len - 1] != 'e' && s[len - 1] != 'i' && s[len - 1] != 'o' && s[len - 1] != 'u' && s[len - 1] != 'n'){
		res = false;
	}
	if(res == true){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	return 0;
}