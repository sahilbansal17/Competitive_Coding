#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int a, b;
    vector<int> adj[n];
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (adj[i].size() == 0) {
            ++res;
            continue;
        }
        int hto = h[i];
        bool po = true;
        for (auto next: adj[i]) {
            if (h[next] >= hto) {
                po = false;
            }
        }
        if (po) {
            ++res;
        }
    }
    cout << res << endl;
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