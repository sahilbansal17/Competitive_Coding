#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    ll x;
    cin >> x;

    ll a = 0, b = 0;
    bool done = false;
    for (int i = -1000; i <= 1000; ++i) {
        for (int j = -1000; j <= 1000; ++j) {
            ll v1 = pow(i, 5);
            ll v2 = pow(j, 5);
            if (v1 - v2 == x) {
                a = i;
                b = j;
                done = true;
                break;
            }
        }
        if (done) {
            break;
        }
    }
    cout << a << " " << b << endl;
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