#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 998244353;

const int MAX = 1e5 + 10;
void solve() {
    int n;
    cin >> n;

    vector<ll> v(n);
    vector<ll> cnt(MAX, 0);

    const int m1 = 100001;
    const int m2 = 100002;
    for (auto &x: v) {
        cin >> x;
        if (x > m1) {
            ++cnt[m2];
        } else {
            ++cnt[x];
        }
    }
    vector<ll> p2(MAX, 0);
    ll p = 1;
    p2[0] = 1;
    for (int i = 1; i <= MAX; ++i) {
        p *= 2ll;
        p %= MOD;
        p2[i] = p;
    }
    // vector<ll> suff(MAX, 0);
    // for (int i = m1; i >= 1; --i) {
    //     suff[i] = suff[i + 1] + cnt[i];
    // }

    ll cur = 1;
    ll rem;
    ll ans = 0;
    for (ll i = 1; i <= m1; ++i) {
        rem = n - cnt[i];
        n = rem;
        ans += (i* ((cur * p2[rem]) % MOD)) % MOD;
        // ans += (i * (cur * p2[rem]) % MOD) % MOD;
        ans %= MOD;
        if (cnt[i] == 0) {
            break;
        }
        cur *= ((p2[cnt[i]] - 1 + MOD) % MOD);
        cur %= MOD;
        // cout << cur << endl;
    }
    cout << ans << endl;

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