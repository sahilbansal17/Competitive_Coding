#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

vector<ll> prices;
int dfs(int cur, vector<int> adj[], int n, vector<bool> &visited, vector<ll> &price) {
    visited[cur] = true;
    ll res = price[cur];
    for (auto next: adj[cur]) {
        if (!visited[next]) {
            res += dfs(next, adj, n, visited, price);
        }
    }
    prices.push_back(res);
    return res;
}

int main() {
    FAST_IO;
    
    int t;
    cin >> t;

    int n;
    while (t --) {
        int n, k, x;
        cin >> n >> k >> x;

        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int u, v;
        vector<int> adj[n];
        for (int i = 0; i < n - 1; ++i) {
            cin >> u >> v;
            --u; 
            --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, 0);
        dfs(0, adj, n, visited, a);

        sort(prices.begin(), prices.end());
        int count = 0;
        int i = 0;
        ll used = 0;
        while (i < n && count < k) {
            used += prices[i];
            ++i;
            ++count;
        }

        if (used > 1ll*x) {
            cout << "0" << endl;
        } else {
            cout << 1ll*x - used << endl;
        }
        prices.clear();
    }
    return 0;
}