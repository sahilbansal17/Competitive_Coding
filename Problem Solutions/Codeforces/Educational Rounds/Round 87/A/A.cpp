#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b >= a) {
        cout << b << endl;
        return;
    }
    
    if (d >= c) {
        cout << -1 << endl;
        return;
    }

    ll k = ceil((1.0*(a - b))/(c - d));
    ll res = b + k*c;
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