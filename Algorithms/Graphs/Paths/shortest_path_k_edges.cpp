// https://www.geeksforgeeks.org/shortest-path-exactly-k-edges-directed-weighted-graph/

// C++ code to find shortest path from source to destination with exactly k edges
// consider -1 in the adjacency matrix as no edge
// i.e. adj[i][j] = -1 denotes that there is no edge from i->j

#include <bits/stdc++.h>
using namespace std;

#define INF 1e6
#define MAX 25

int adj[MAX][MAX];
int dp[MAX][MAX][MAX];

/*	dp[i][j][k] denotes the smallest length of path from i->j with exactly k edges
*	Recursive relation:
*	dp[i][j][k] = min(dp[i][j][k], wt(v, j) + dp[i][v][k - 1]) for all v such that adj[v][j] != INF
*/

int weightSmallestPathK(int V, int source, int dest, int edges) {
	if (dp[source][dest][edges] != -1) {
		return dp[source][dest][edges];
	}

	if (source == dest && edges == 0) {
		return dp[source][dest][edges] = 0;
	}
	if (adj[source][dest] == 1 && edges == 1) {
		return dp[source][dest][edges] = adj[source][dest];
	}
	if (edges <= 0) {
		return INF;
	}

	dp[source][dest][edges] = INF;
	for (int i = 0; i < V; i ++) {
		if (adj[i][dest] != INF) {
			// source -> dest = source -> i + edge(i -> dest)
			dp[source][dest][edges] = min(dp[source][dest][edges], 
										adj[i][dest] + 
										weightSmallestPathK(V, source, i, edges - 1));
		}
	}
	return dp[source][dest][edges];
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
				if (adj[i][j] == -1) {
					adj[i][j] = INF;
				}
			}
		}

		int u, v, k;
		cin >> u >> v >> k;
		cout << weightSmallestPathK(n, u, v, k) << endl;

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