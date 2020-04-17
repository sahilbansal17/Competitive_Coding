#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    ll x, y;
    vector<ll> health(n, 0);
    vector<ll> damage(n, 0);
    for (ll i = 0; i < n; ++i) {
        cin >> x >> y;
        health[i] = x;
        damage[i] = y;
    }
    
    vector<ll> cost(2*n, 0);
    for (int i = 0; i < n - 1; ++i) {
        cost[i] = health[i + 1] - min(health[i + 1], damage[i]);
    }
    cost[n - 1] = health[0] - min(health[0], damage[n - 1]);

    // cost[n] = cost[0]
    for (int i = n; i < 2*n; ++i) {
        cost[i] = cost[i - n];
    }
    // prefix cost
    for (int i = 1; i < 2*n; ++i) {
        cost[i] += cost[i - 1];
    }

    ll cur_cost;
    ll res = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        cur_cost = health[i] + cost[i + n - 2];
        if (i >= 1) {
            cur_cost -= cost[i - 1];
        }
        res = min(res, cur_cost);
    }
    cout << res << endl;
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