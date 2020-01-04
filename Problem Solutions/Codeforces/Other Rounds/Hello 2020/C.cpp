#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const int MAX = 250010;
int main() {
    FAST_IO;

    ll n, m;
    cin >> n >> m;

    vector<ll> fact(MAX);
    fact[0] = 1;

    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1]*(1ll*i);
        fact[i] %= m;
    }

    ll res = 0;
    ll cur;
    for (int i = n; i >= 1; --i) {
        cur = (fact[i] * fact[n - i + 1]) % m;
        cur *= i;
        cur %= m;
        res += cur;
        res %= m;
    }

    cout << res << endl;
    return 0;
}