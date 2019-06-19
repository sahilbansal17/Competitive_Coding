// https://practice.geeksforgeeks.org/problems/possible-paths/0
// https://www.geeksforgeeks.org/count-possible-paths-source-destination-exactly-k-edges/

// C++ code to count all possible walks from source to destination with exactly k edges

#include <bits/stdc++.h>
using namespace std;

#define MAX 25
int adj[MAX][MAX];
int dp[MAX][MAX][MAX];

/*	dp[i][j][k] denotes the no. of walks from i->j with exactly k edges
*	Recursive relation:
*	dp[i][j][k] = dp[i][v][k - 1] for all v such that adj[v][j] = 1
*/

int countPossibleWalksK(int V, int source, int dest, int edges) {
	if (dp[source][dest][edges] != -1) {
		return dp[source][dest][edges];
	}

	if (source == dest && edges == 0) {
		return dp[source][dest][edges] = 1;
	}
	if (adj[source][dest] == 1 && edges == 1) {
		return dp[source][dest][edges] = 1;
	}
	if (edges <= 0) {
		return 0;
	}

	int count = 0;
	for (int i = 0; i < V; i ++) {
		if (adj[i][dest] == 1) {
			// source -> dest = source -> i + edge(i -> dest)
			count += countPossibleWalksK(V, source, i, edges - 1);
		}
	}
	return dp[source][dest][edges] = count;
}

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

		memset(adj, 0, sizeof(adj));
		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				cin >> adj[i][j];
			}
		}

		int u, v, k;
		cin >> u >> v >> k;
		cout << countPossibleWalksK(n, u, v, k) << endl;

		/*/
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				cerr << dp[i][j][2] << " ";
			}
			cerr << endl;
		}
		//*/
	}
	return 0;
}