#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;

    ll res = 0;
    // pick cards with value 1
    res += min(a, k);
    k -= min(a, k);

    if (k == 0) {
        cout << res << endl;
        return;
    }

    // pick cards with value 0
    k -= min(b, k);
    if (k == 0) {
        cout << res << endl;
        return;
    }

    // pick cards with value -1
    res -= min(c, k);
    k -= min(c, k);
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