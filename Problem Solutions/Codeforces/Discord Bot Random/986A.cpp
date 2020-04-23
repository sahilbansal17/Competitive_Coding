#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'
const int MAX = 2e5 + 10;

int main() {
    FAST_IO;

    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<int> type[k]; // contains the town that has this type
    int t;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        --t;
        type[t].push_back(i);
    }

    int u, v;
    vector<int> adj[n];
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> costs[n]; // cost for each good in each town
    // run multi-source bfs with all towns that have a particular type
    for (int i = 0; i < k; ++i) {
        queue<pair<int, int>> q;
        vector<int> vis(n, 0);
        for (auto town: type[i]) {
            q.push({town, 0});
            vis[town] = 1;
            costs[town].push_back(0);
        }
        while (!q.empty()) {
            auto fr = q.front();
            int town = fr.first;
            int dist = fr.second;
            q.pop();
            for (auto next: adj[town]) {
                if (!vis[next]) {
                    q.push({next, dist + 1});
                    vis[next] = 1;
                    costs[next].push_back(dist + 1);
                }
            }
        }
    }

    // sort the costs and find sum of first s elements for each town
    for (int i = 0; i < n; ++i) {
        // sort(costs[i].begin(), costs[i].end());
        nth_element(costs[i].begin(), costs[i].begin() + s, costs[i].end());
        int res = 0;
        for (int j = 0; j < s; ++j) {
            res += costs[i][j];
        }
        cout << res << " ";
    }
    cout << endl;
    
    return 0;
}