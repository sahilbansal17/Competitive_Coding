/**
 * This problem can be used to illustrate the concept of disconnected components in a graph.
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

#define int ll

const ll MOD = 1e9 + 7;
template<typename T>
T power (T a, T b, ll M = MOD) {
    a %= MOD;
    T res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }
    return res;
}

void dfs(int src, vector<int> adj[], vector<int>& vis, int& cur_size) {
    vis[src] = 1;
    ++cur_size;
    for (auto next: adj[src]) {
        if (!vis[next]) {
            dfs(next, adj, vis, cur_size);
        }
    }
}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<int> adj[n];
    int x, y, type;
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y >> type;
        --x;
        --y;
        // connect only the red edges
        if (type == 0) {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }
    ll ans = power(n, k);
    vector<int> vis(n, 0);
    ll cur_size;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            // find the size of current component with only red edges
            cur_size = 0;
            dfs(i, adj, vis, cur_size);
            // remove the bad sequences from the ans, with no black edges
            ans -= power(cur_size, k);
            // take care of modulo
            ans += MOD;
            ans %= MOD;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    FAST_IO;

    int t;
    // cin >> t; 
    t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}