#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        if (n % k == 0) {
            cout << n << endl;
        } else {
            ll res = (n/k) * k;
            res += min(k/2, n - res);
            cout << res << endl;
        }
    }    
    
    return 0;
}