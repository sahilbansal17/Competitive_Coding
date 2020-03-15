/*
 * Problem Link: https://www.codechef.com/problems/PS102
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

void multiply(ll f[][2], ll g[][2]) {
    ll a = (f[0][0] * g[0][0] + f[0][1] * g[1][0]) % MOD;
    ll b = (f[0][0] * g[0][1] + f[0][1] * g[1][1]) % MOD;
    ll c = (f[1][0] * g[0][0] + f[1][1] * g[1][0]) % MOD;
    ll d = (f[1][0] * g[0][1] + f[1][1] * g[1][1]) % MOD;
    f[0][0] = a;
    f[0][1] = b;
    f[1][0] = c;
    f[1][1] = d;
}

void power(ll f[2][2], ll n) {
    ll g[2][2] = {{1, 1}, {1, 0}};
    if (n == 0 || n == 1) {
        return ;
    }
    power(f, n/2);
    multiply(f, f);
    if (n % 2 == 1) {
        multiply(f, g);
    }
}

ll fib(ll n) {
    ll f[2][2] = {{1, 1}, {1, 0}};
    if (n == 0) {
        return 0;
    }
    power(f, n - 1);
    return f[0][0] % MOD;
}
int main() {

    FAST_IO;
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        cout << fib(n + 2) << endl;
    }
    return 0;
}