// https://practice.geeksforgeeks.org/problems/shortest-path-from-1-to-n/0
// https://www.geeksforgeeks.org/shortest-path-for-directed-acyclic-graphs/

/* 	C++ code to find shortest path from source vertex in a given
*	Directed Acyclic Graph (DAG) in O(V + E) algorithm
*/

#include <bits/stdc++.h>
using namespace std;

int main () {

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
	#endif

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		int dp[n + 1];
		memset(dp, 10000, sizeof(dp));
		dp[1] = 0;
		for (int i = 2; i <= n; i ++) {
			dp[i] = min(dp[i - 1] + 1, dp[i]);
			if (i/3 * 3 == i) {
				dp[i] = min(dp[i/3] + 1, dp[i]);
			}
		}

		cout << dp[n] << endl;
	}

	return 0;
}