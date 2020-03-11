#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main() {

    FAST_IO;
    
    ll t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> pre(n), suff(n);
        pre[0] = a[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = gcd(a[i], pre[i - 1]);
        }

        suff[n - 1] = a[n - 1];
        for (int j = n - 2; j >= 0; --j) {
            suff[j] = gcd(a[j], suff[j + 1]);
        }

        int res = max(a[0], a[n - 1]);
        // int cur;
        // for (int i = 0; i < n; ++i) {
        //     for (int j = i; j < n; ++j) {
        //         // i --> j
        //         // consider ...(i - 1), (j + 1)...
        //         cur = 0;
        //         if (i - 1 >= 0) {
        //             cur = pre[i - 1];
        //         }
        //         if (j + 1 < n) {
        //             cur = gcd(cur, suff[j + 1]);
        //         }
        //         if (cur > res) {
        //             res = cur;
        //         }
        //     }
        // }
        cout << res << endl;
    }
    return 0;
}