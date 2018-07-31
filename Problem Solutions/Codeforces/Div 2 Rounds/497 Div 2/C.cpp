#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	#endif

	int n, val;
	cin >> n;

	vector <int> a, b;
	for(int i = 0; i < n; i ++){
		cin >> val;
		a.push_back(val);
		b.push_back(val);
	}
	
	sort(b.begin(), b.end());

	vector <int> :: iterator upper;
	int res = 0;
	for(int i = 0; i < n; i ++){
		upper = upper_bound(b.begin(), b.end(), a[i]);
		if(upper != b.end()){
			// cout << *upper << " ";
			res ++;
			b.erase(upper);
		}
		else{
			// cout << *b.begin() << " ";
			b.erase(b.begin());
		}
	}

	cout << res;
	return 0;
}