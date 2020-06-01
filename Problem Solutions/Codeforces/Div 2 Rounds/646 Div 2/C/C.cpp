#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> adj[n + 1];
    int u, v;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   if (adj[x].size() == 1 || n == 1 || n % 2 == 0) {
       cout << "Ayush" << endl;
   } else {
       cout << "Ashish" << endl;
   }
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}