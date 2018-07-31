#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	#endif

	int n;

	cin >> n;

	int w[100001], h[100001];

	for(int i = 0; i < n ; i ++){
		cin >> w[i] >> h[i];
	}
	
	int previous, current_max, current_min;
	if(w[0] > h[0]){
		previous = w[0];
	}
	else{
		previous = h[0];
	}

	bool exist = true;
	for(int i = 1; i < n; i ++){
		current_max = h[i];
		current_min = h[i];
		if(w[i] > current_max){
			current_max = w[i];
		}
		if(w[i] < current_min){
			current_min = w[i];
		}
		if(previous >= current_max){
			previous = current_max;
		}
		else if(previous >= current_min){
			previous = current_min;
		}
		else{
			exist = false;
			break;
		}
	}
	if(!exist){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
	}
	return 0;
}