#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

int main() {
    FAST_IO;
    
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> h(n);
        ll sum = 0;
        for (auto &x: h) {
            cin >> x;
            sum += 1ll*x;
        }

        vector<int> maxInc(n, 1), maxIncRev(n, 1);
        for (int i = 1; i < n; ++i) {
            if (h[i] >= maxInc[i - 1] + 1) {
                maxInc[i] = maxInc[i - 1] + 1;
            } else {
                maxInc[i] = h[i];
            }
        }
        for (int i = n - 2; i >= 0; --i) {
            if (h[i] >= maxIncRev[i + 1] + 1) {
                maxIncRev[i] = maxIncRev[i + 1] + 1;
            } else {
                maxIncRev[i] = h[i];
            }
        }

        ll optimal_h = 1;
        for (int i = 0; i < n; ++i) {
            ll cur_h = min(maxInc[i], maxIncRev[i]);
            if (cur_h > optimal_h) {
                optimal_h = cur_h;
            }
        }
        // cout << optimal_h << ": ";
        ll res = sum - (optimal_h * optimal_h);
        cout << res << endl;
    }
    return 0;
}