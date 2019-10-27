#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
int main() {
    FAST_IO;
    
    ll n, p;
    cin >> n >> p;

    // find the min value of k such that 
    // no. of set bits in (n - k*p) is the = k

    vector<int> bits(64, 0);
    for (int k = 1; k <= 64; ++k) {
        ll val = n - 1ll*k*p;
        if (val < 0) {
            break;
        }
        int setBits = __builtin_popcount(val);
        if (setBits == k) {
            cout << k << endl;
            return 0;
        } else if (setBits < k) {
            for (int i = 0; i < 64; ++i) {
                if (val & (1ll << i)) { // don't make the mistake of using (1 << i)
                // since otherwise treated as integer and not LL
                    bits[i] = 1;
                } else {
                    bits[i] = 0;
                }
            }
            int cur = 63;
            while (setBits < k && cur > 1) {
                if (bits[cur] > 0) {
                    bits[cur - 1] += 2;
                    --bits[cur];
                    ++setBits;
                } else {
                    --cur;
                }
            }
            if (setBits == k) {
                cout << k << endl;
                return 0;
            }
        } 
    }
    cout << "-1" << endl;
    return 0;
}