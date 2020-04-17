#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

ll dfs(int cur, int d, vector<int> adj[], vector<ll>& contri) {
    ll cnt = 1;
    contri[cur] = 0;
    for (auto next: adj[cur]) {
        if (contri[next] == -1) {
            cnt += dfs(next, d + 1, adj, contri);
        }
    }
    contri[cur] = 1ll*d - cnt + 1;
    return cnt;
}

void solve() {
    int n, k;
    cin >> n >> k;

    int x, y;

    vector<int> adj[n];
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        --x;
        --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<ll> contri(n, -1);

    dfs(0, 0, adj, contri);

    sort(contri.begin(), contri.end());
    reverse(contri.begin(), contri.end());

    ll res = 0;
    for (int i = 0; i < k; ++i) {
        res += contri[i];
    }

    cout << res << endl;
}

int main() {
    FAST_IO;

    int t;
    t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}