// Incomplete and incorrect approach
// Will be fixed

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 200010;
const ll MOD = 1000000007;

vector <pair <int, int> > adj_list[MAX];
vector <int> special(MAX, 0);

int solve(int src, int dst) {

	queue <pair <int, pair <int, int> > > q; // {count_special, {node, distance}};
	if (special[src]) {
		q.push({1, {src, 0}});
	}
	else {
		q.push({0, {src, 0}});
	}

	pair <int, pair <int, int> > top;

	vector <int> visited(MAX, 0);
	while (!q.empty()) {
		top = q.front();
		int count_special = top.first;
		int node = top.second.first;
		int dist = top.second.second;
		if (node == dst) {
			return dist;
		}
		for (int i = 0; i < adj_list[node].size(); i ++) {
			int next = adj_list[node][i].first;
			int weight = adj_list[node][i].second;
			if (!visited[next]) {
				if (special[next] && count_special == 0) {
					q.push({1, {next, dist + weight}});
				}
				else if (!special[next]) {
					q.push({count_special, {next, dist + weight}});
				}
			}
		}
		q.pop();
		visited[node] = true;
	}
	return -1;
}
int main () {

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
	#endif

	int num_vertices, num_edges;
	cin >> num_vertices >> num_edges;

	int u, v, w;
	for (int i = 0; i < num_edges; i ++) {
		cin >> u >> v >> w;
		adj_list[u].push_back({v, w});
	}

	int num_special;
	cin >> num_special;

	for (int i = 0; i < num_special; i ++) {
		cin >> u;
		special[u] = 1;
	}

	int src, dst;
	cin >> src >> dst;

	// find a valid path from src to dst with minimum cost
	// for any 2 adjacent edges x and y:
	// 0.5*weight(x) <= weight(y) <= 2*weight(x)
	// the path must contain exactly one special vertex
	cout << solve(src, dst);
	return 0;
}