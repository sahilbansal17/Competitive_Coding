#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

vector<pair<int, int>> edgeList;
void dfs(int src, set<int> adj[], vector<int>& visited) {
    visited[src] = 1;
    for (auto next: adj[src]) {
        int vert = (edgeList[next].first ^ edgeList[next].second ^ src);
        if (!visited[vert]) {
            dfs(vert, adj, visited);
        }
    }
}

void hierholzer(int src, set<int> adj[]) {
    while (!adj[src].empty()) {
        int e = *adj[src].begin();
        int to = src ^ edgeList[e].first ^ edgeList[e].second;
        // res.push_back({src ,to});
        if (edgeList[e].first != src) {
            swap(edgeList[e].first, edgeList[e].second);
        }
        adj[src].erase(adj[src].begin());
        adj[to].erase(e);
        hierholzer(to, adj);
    }
}
void solve() {
    int v, e;
    cin >> v >> e;

    int x, y;
    set<int> adj[v + 1];
    for (int i = 0; i < e; ++i) {
        cin >> x >> y;
        adj[x].insert(i);
        adj[y].insert(i);
        edgeList.push_back({x, y});
    }

    vector<int> visited(v + 1, 0);
    dfs(1, adj, visited);
    for (int i = 1; i <= v; ++i) {
        if (!visited[i] || adj[i].size() % 2 != 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    hierholzer(1, adj);
    for (auto edge: edgeList) {
        cout << edge.first << " " << edge.second << endl;
    }
}

int main() {
    FAST_IO;

    int t;
    // cin >> t;
    t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}