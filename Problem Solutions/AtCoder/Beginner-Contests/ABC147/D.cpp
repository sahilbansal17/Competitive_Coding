/*
 * Reference: https://www.geeksforgeeks.org/sum-xor-pairs-array/
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const ll MOD = 1000000007LL;

int main() {

    FAST_IO;

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll res = 0;
    ll mul = 1;
    for (int k = 0; k < 60; ++k) {
        ll set = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] & (1ll << k)) {
                ++set;
            }
        }
        res += ((set * (n - set)) % MOD) * mul;
        res %= MOD;
        mul *= 2;
        mul %= MOD;
    }
    cout << res << endl;
    return 0;
}