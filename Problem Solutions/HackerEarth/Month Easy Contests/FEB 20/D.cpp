#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const int MAX = 100010;
bool visited[MAX];

vector<ll> paths(6, 0);

void solve(int cur, vector<pair<int, int>> adj[], vector<int>& done, int distColor) {
    visited[cur] = 1;
    if (distColor >= 1) {
        ++paths[distColor];
    }

    for (auto nxt: adj[cur]) {
        int v = nxt.first;
        int c = nxt.second;
        if (!visited[v]) {
            bool changed = false;
            if (!done[c]) {
                done[c] = 1;
                changed = true;
                ++distColor;
            }
            // cout << cur << "->" << v << ", dist: " << distColor << endl;
            solve(v, adj, done, distColor);
            if (changed) {
                done[c] = 0;
                --distColor;
            }
        }
    }
}

int main() {
    FAST_IO;

    int n, k;
    cin >> n >> k;

    int x, c;
    vector<pair<int, int>> adj[n];
    for (int i = 1; i < n; ++i) {
        cin >> x >> c;
        --x;
        adj[i].push_back({x, c});
        adj[x].push_back({i, c});
    }

    vector<int> done(5, 0);
    for (int i = 0; i < n; ++i) {
        memset(visited, 0, sizeof(visited));
        done.clear();
        solve(i, adj, done, 0);
    }

    for (int i = 1; i <= k; ++i) {
        cout << paths[k] << " ";
    }
    cout << endl;
    return 0;
}