#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const int MAX = 100010;
bool visited[MAX];

bool twoBranches(int cur, vector<int> adj[]) {
    visited[cur] = 1;
    int cnt = 0;
    bool res = false;
    for (auto nxt: adj[cur]) {
        if (!visited[nxt]) {
            ++cnt;
            res |= twoBranches(nxt, adj);
        }
    }
    if (cnt > 1) {
        return true;
    }
    return res;
}

int main() {
    FAST_IO;

    int n;
    cin >> n;

    int x;
    vector<int> adj[n];
    // start from 2nd (i = 1) vertex
    for (int i = 1; i < n; ++i) {
        cin >> x;
        --x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    vector<ll> val(n);
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
        res += val[i];
    }

    memset(visited, 0, sizeof(visited));
    // root = 0
    if (twoBranches(0, adj)) {
        cout << res << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}