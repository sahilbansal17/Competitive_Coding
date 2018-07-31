#include <bits/stdc++.h>
using namespace std;

int main(){
	
	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	#endif

	int n, val;
	vector <int> a;

	cin >> n;	
	for(int i = 0; i < n; i ++){
		cin >> val;
		a.push_back(val);
	}

	int res = 0;
	int prev = a[0];
	int adj_count = 1;
	for(int i = 1; i < n; i ++){
		if(a[i] == prev){
			adj_count ++;
		}
		else{
			prev = a[i];
		}
		if(adj_count == 2){
			res ++;
			i ++;
			prev = a[i];
			adj_count = 1;
		}
	}

	cout << res;
	return 0;
}