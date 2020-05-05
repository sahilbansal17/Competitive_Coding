#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    ll maxi = arr[0];
    ll diff;
    ll res = 0;
    for (int i = 1; i < n; ++i) {
        ll cur = arr[i];
        if (cur < maxi) {
            diff = maxi - cur;
            ll steps = 1 + log2(diff);
            res = max(res, steps);
        }
        maxi = max(maxi, cur);
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