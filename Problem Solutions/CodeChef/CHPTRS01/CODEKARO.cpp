/*
 * Gives Wrong Answer: To be Fixed
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const ll MOD = 1e9 + 7;

ll power (ll x, ll y) {
    ll res = 1;
    x %= MOD;
    while (y) {
        if (y & 1) {
            res *= x;
            res %= MOD;
        }
        y >>= 1;
        x *= x;
        x %= MOD;
    }
    return res;
}

ll modInverse(ll n) {
    return power(n, MOD - 2);
}

ll ncrModPFermat(ll n, ll r) {
    if (r == 0) {
        return 1;
    }
    ll fact[n + 1];
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    return (fact[n] * modInverse(fact[r]) % MOD * modInverse(fact[n - r]) % MOD) % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        ll l;
        cin >> l;

        if (l == 1) {
            cout << 1 << endl;
            continue;
        }
        // ll res = ncrModPFermat(26, 26 - k);
        ll res = 2;
        res *= power(52, l/2);
        res %= MOD;
        if (l & 1) {
            // middle position
            res *= 52ll;
            res %= MOD;
        }

        ll extra = 1;
        extra *= power(k, l/2);
        extra %= MOD;
        extra *= power(2, l/2);
        extra %= MOD;
        if (l & 1) {
            extra *= 52ll;
            extra %= MOD;
        }

        extra = 0; // no mixed case
        res += extra;
        res %= MOD;

        // cout << res << endl;
        ll total = power(52, l);
        // cout << total << endl;
        res *= modInverse(total);
        res %= MOD;
        cout << res << endl;
    }
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