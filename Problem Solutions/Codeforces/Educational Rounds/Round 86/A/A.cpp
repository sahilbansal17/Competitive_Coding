#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;

    ll mn = min(x, y);
    ll mx = max(x, y);

    ll res = (mx - mn)*a + min(mn*b, 2*mn*a);
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