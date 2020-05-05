#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    ll a, b, n;
    cin >> a >> b >> n;

    ll x = min(b - 1, n);

    ll res = floor((1.0*a*x)/b) - a*floor((1.0 * x)/b);
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