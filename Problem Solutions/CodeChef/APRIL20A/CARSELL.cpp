#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const ll MOD = 1000000007;
void solve() {
    int n;
    cin >> n;

    vector<ll> price(n);
    for (int idx = 0; idx < n; ++idx) {
        cin >> price[idx];
    }
    sort(price.begin(), price.end());
    reverse(price.begin(), price.end());

    ll max_profit = 0;
    for (int idx = 0; idx < n; ++idx) {
        if (price[idx] - idx <= 0) {
            break;
        }
        max_profit += (price[idx] - idx + MOD) % MOD;
        max_profit %= MOD;
    }
    cout << max_profit << endl;
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