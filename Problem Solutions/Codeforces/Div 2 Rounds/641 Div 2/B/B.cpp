#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }

    vector<ll> dp(n + 1, 0);
    ll res = 1;
    for (int i = 1; i <= n; ++i) {
        ll cur = 1;
        for (int j = 1; j <= sqrt(i); ++j) {
            if (i % j == 0 && arr[j] < arr[i]) {
                cur = max(cur, 1 + dp[j]);
            }
            if (i % j == 0 && arr[i/j] < arr[i]) {
                cur = max(cur, 1 + dp[i/j]);
            }
        }
        dp[i] = cur;
        res = max(res, dp[i]);
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