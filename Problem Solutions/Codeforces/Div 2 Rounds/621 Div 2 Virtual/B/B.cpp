#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> fav(n);
    ll maxi = 0;
    bool exists = false;
    for (auto &f: fav) {
        cin >> f;
        if (f > maxi) {
            maxi = f;
        }
        if (f == x) {
            exists = true;
        }
    }

    int res = 0;
    if (maxi == x || exists) {
        res = 1;
    } else if (maxi < x) {
        res = x/maxi;
        if (x % maxi != 0) {
            ++res;
        }
    } else {
        // maxi > x
        res = 2;
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