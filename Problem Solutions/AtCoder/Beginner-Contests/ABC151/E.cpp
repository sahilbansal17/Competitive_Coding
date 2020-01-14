#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const int MAX = 100010;
const ll MOD = 1e9 + 7;

ll fact[MAX];
void compute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        fact[i] = fact[i - 1]*i;
        fact[i] %= MOD;
    }
}

ll myPower(ll a, ll b, ll mod = MOD) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1ll;
    }
    return res;
}

ll modInverse(ll a, ll mod = MOD) {
    return myPower(a, mod - 2, mod);
}

int main() {

    FAST_IO;

    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (auto &i: a) {
        cin >> i;
    }

    ll res = 0;
    ll add = 0;
    ll subt = 0;

    compute_factorials();
    sort(a.begin(), a.end());

    ll div = fact[k - 1];
    for (int i = k - 1; i < n; ++i) {
        ll multiplier = fact[i];
        ll div2 = fact[i - (k - 1)];
        multiplier *= modInverse(div);
        multiplier %= MOD;
        multiplier *= modInverse(div2);
        multiplier %= MOD;
        add += (a[i] * multiplier) % MOD;
    }

    for (int i = 0; i < n - k + 1; ++i) {
        ll multiplier = fact[n - i - 1];
        ll div2 = fact[n - i - 1 - (k - 1)];
        multiplier *= modInverse(div);
        multiplier %= MOD;
        multiplier *= modInverse(div2);
        multiplier %= MOD;
        subt += (a[i] * multiplier) % MOD;
    }
    res = (add - subt + MOD) % MOD;

    cout << res << endl;
    return 0;
}