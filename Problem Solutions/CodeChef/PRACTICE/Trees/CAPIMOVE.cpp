#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> sizes(n);
    int sz;
    for (int i = 0; i < n; ++i) {
        cin >> sz;
        sizes.push_back({sz, i});
    }
    sort(sizes.begin(), sizes.end(), greater<pair<int, int>>());

    int u, v;
    set<int> adj[n];
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        --u;
        --v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<int> res(n);
    set<int> remaining_vertices;
    for (int i = 0; i < n; ++i) {
        remaining_vertices.insert(i);
    }
    for (int i = 0; i < n; ++i) {
        int cur = sizes[i].second;
        vector<int> to_remove;
        for (auto next: remaining_vertices) {
            if (next == cur) {
                continue;
            }
            // not adjacent
            if (adj[cur].find(next) == adj[cur].end()) {
                res[next] = cur;
                to_remove.push_back(next);
            }
        }
        for (auto rm: to_remove) {
            remaining_vertices.erase(rm);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] + 1 << " ";
    }
    cout << endl;
}

int main () {
    FAST_IO;

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}