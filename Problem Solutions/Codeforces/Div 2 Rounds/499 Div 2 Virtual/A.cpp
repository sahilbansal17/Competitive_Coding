#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	#endif
	
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;

	sort(s.begin(), s.end());
	int min_weight = s[0] - 'a' + 1;
	int used = 1, current, prev = 0;

	for(int i = 1; i < n; i ++){
		current = i;
		if(used == k){
			break;
		}
		if(s[current] - s[prev] >= 2){
			min_weight += s[current] - 'a' + 1;
			prev = current;
			used ++;
		}
	}
	if(used < k){
		cout << "-1";
	}
	else{
		cout << min_weight;
	}
	return 0;
}