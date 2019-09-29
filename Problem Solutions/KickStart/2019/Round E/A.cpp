#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const int MAX = 100010;
vector<int> adj[MAX];
vector<int> visited(MAX, 0);

void dfs(int source) {
	visited[source] = 1;
	for (auto next: adj[source]) {
		if (!visited[next]) {
			dfs(next);
		}
	}
}

void resetAll() {
	for (int i = 1; i <= MAX; ++i) {
		adj[i].clear();
		visited[i] = 0;
	}
}

int main() {
  FAST_IO;
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
  	resetAll();
    int n, m;
    cin >> n >> m;

    int u, v;
    for (int j = 0; j < m; ++j) {
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    // find the no. of connected components
    int cc = 0;
    for (int j = 1; j <= n; ++j) {
    	if (!visited[j]) {
    		dfs(j);
    		++cc;
    	}
    }

    int res = (n - cc) + (cc - 1)*2;
    cout << "Case #" << i + 1 << ": " << res << endl;
  }
  return 0;
}