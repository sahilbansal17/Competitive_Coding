#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    ll n, k;
    cin >> n >> k;

    ll factor = 2;
    ll maxFactor = sqrt(n);
    while (factor <= maxFactor) {
        if (n % factor == 0) { // smallest factor except 1
            break;
        }
        ++factor;
    }
    if (n % factor != 0) { // no factor in [2, sqrt(n)], so f(n) = n
        factor = n;
    }

    ll res = n + factor + (k - 1)*2; // 2 for the remaining (k - 1) times
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