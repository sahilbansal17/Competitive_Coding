#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    ll n;
    cin >> n;

    ll cur = 3;
    ll res = 0;
    ll k = 1;
    while (cur <= n) {
        ll term = (cur + cur - 2) * 2;
        res += term*k;
        cur += 2;
        ++k;
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