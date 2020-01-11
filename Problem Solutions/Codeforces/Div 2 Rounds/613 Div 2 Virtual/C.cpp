#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    FAST_IO;

    ll x;
    cin >> x;

    ll min_possible = x;
    ll res_a = 1;
    ll res_b = x;
    for (int i = 1; i < sqrt(x); ++i) {
        ll a = i;
        ll b = x/i;
        if ((a * b)/gcd(a, b) == x) {
            if (b < min_possible) {
                min_possible = b;
                res_a = a;
                res_b = b;
            }
        }
    }
    cout << res_a << " " << res_b << endl;
    return 0;
}