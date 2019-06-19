// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/explorers-birthday/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MAX = 500010;
const ll MOD = 1000000007;

vector <pair <int, int> > adj_list[MAX];
vector <bool> visited(MAX, 0);
ll res = 0;

ll dfs (int u) {
	visited[u] = true;

	ll child = 0, child_sum = 0;
	for (int next_idx = 0; next_idx < adj_list[u].size(); next_idx ++) {
		pair <int, int> edge = adj_list[u][next_idx];
		int v = edge.first;
		int w = edge.second;

		if (!visited[v]) {
			// get the answer of the subtree rooted at v
			child = dfs(v);
			// add the edge from u->v with weight w to result (all subtree nodes with root u)
			child = (w * child) % MOD;
			child %= MOD;
			child += w;
			child %= MOD;

			res += child;
			res %= MOD;
			// consider child pairs with all other child (stored in child_sum)
			res += (child_sum * child) % MOD;
			res %= MOD;
			// update the child sum
			child_sum += child;
			child_sum %= MOD;
		}
	}
	return child_sum;
}

int main () {

	int num_nodes;
	cin >> num_nodes;

	int u, v;
	ll w;
	for (int i = 0; i < num_nodes - 1; i ++) {
		cin >> u >> v >> w;
		adj_list[u].push_back({v, w});
		adj_list[v].push_back({u, w});
	}

	ll child_sum = dfs(1);
	cout << res << endl;

	return 0;
}