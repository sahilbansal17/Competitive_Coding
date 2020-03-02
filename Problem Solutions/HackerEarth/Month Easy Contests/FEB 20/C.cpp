#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int n, q;
    cin >> n >> q;

    int t, l, r, x;
    vector<ll> a(n, 0);
    while (q--) {
        cin >> t >> l >> r;
        --l;
        --r;
        if (t == 4) {
            // sum
            ll res = 0;
            for (int i = l; i <= r; ++i) {
                res += a[i];
            }
            cout << res << endl;
        } else if (t == 5) {
            ll res = 0;
            for (int i = l; i <= r; ++i) {
                res ^= a[i];
            }
            cout << res << endl;
        } else {
            cin >> x;
            if (t == 1) {
                for (int i = l; i <= r; ++i) {
                    a[i] = a[i] | x;
                }
            } else if (t == 2) {
                for (int i = l; i <= r; ++i) {
                    a[i] = a[i] & x;
                }
            } else {
                for (int i = l; i <= r; ++i) {
                    a[i] = a[i] ^ x;
                }
            }
        }
    }

    return 0;
}