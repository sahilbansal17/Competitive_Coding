#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	#endif

	int t, current, len, max, max_consec;
	cin >> t;

	string s;
	while(t --){
		cin >> s;
		current = 1;
		max = 1;
		max_consec = 1;

		int start = 0;
		len = s.length();
		while(start < len && s[start] == '='){
			start ++;
		}
		if(s[0] == '='){
			max_consec = 0;
			max = 0;
		}
		for(int i = start; i < len; i ++){
			if(s[i] == s[i - 1]){
				max_consec ++;
			}
			else if(s[i] == '='){
				s[i] = s[i - 1];
				continue;
			}
			else{
				if(max_consec > max){
					max = max_consec;
				}
				max_consec = 1;
			}
		}
		if(max_consec > max){
			max = max_consec;
		}
		cout << max + 1 << "\n";
	}
	return 0;
}