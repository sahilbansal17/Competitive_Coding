#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

const ll NEG_INF = -10000000000;

void solve() {
    int n;
    cin >> n;

    ll sum = 0;
    ll nsum = NEG_INF;
    ll psum = NEG_INF;
    ll x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x < 0) {
            if (psum != NEG_INF) {
                sum += psum;
                psum = NEG_INF;
            }
            nsum = max(nsum, x);
        } else {
            if (nsum != NEG_INF) {
                sum += nsum;
                nsum = NEG_INF;
            }
            psum = max(psum, x);
        }
    }
    if (nsum != NEG_INF) {
        sum += nsum;
    } else if (psum != NEG_INF) {
        sum += psum;
    }
    cout << sum << endl;
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