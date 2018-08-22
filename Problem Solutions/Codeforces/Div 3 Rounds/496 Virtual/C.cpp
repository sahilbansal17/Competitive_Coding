#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	#endif

	int n, val;
	vector <int> a;
	scanf("%d", &n);

	// maintain the frequencies of each elements in the sequence
	map <int, int> freq;
	for (int i = 0; i < n; i ++){
		scanf("%d", &val);
		a.push_back(val);
		freq[val] ++;
	}

	// for every a[i] check for each power of 2 from 0 to 30, whether
	// power - a[i] exists in the sequence and is not the same.
	// if it doesn't exist for some a[i], then we need to delete it
	// so increment the counter 

	int ans = 0;
	for (int i = 0; i < n; i ++){
		bool exist = false;
		for (int j = 0; j < 31; j ++){
			int x = (1 << j) - a[i];
			if(freq.count(x) && (freq[x] > 1 || (freq[x] == 1 && x != a[i]) )){
				exist = true;
				break;
			}
		}
		if(!exist){
			ans ++;
		}
	}

	printf("%d", ans);
	return 0;
}