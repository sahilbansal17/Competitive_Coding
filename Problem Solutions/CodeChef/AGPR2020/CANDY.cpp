#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

int main() {

    FAST_IO;
    
    ll t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;

        ll res = n;
        res += (n/2) * k;
        if (n & 1) {
            res += 2*k;
        }
        cout << res << endl;
    }

    return 0;
}