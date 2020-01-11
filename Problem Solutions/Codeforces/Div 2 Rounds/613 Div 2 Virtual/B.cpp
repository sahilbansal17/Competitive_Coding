#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; ++i) {
        cin >> n;

        ll sum = 0;
        ll max_sum = 0;
        ll cur_pos_sum = 0;
        int l = 0, r;
        int max_l = -1, max_r = -1;
        ll x;

        vector<ll> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> x;
            a[j] = x;
            sum += x;
            if (cur_pos_sum + x > 0) {
                cur_pos_sum += x;
                if (cur_pos_sum > max_sum) {
                    max_sum = cur_pos_sum;
                    max_l = l;
                    max_r = j;
                }
            } else {
                cur_pos_sum = 0;
                l = j + 1;
            }
        }
        if (max_l == 0 && max_r == n - 1) {
            int m1 = max_sum - a[0];
            int m2 = max_sum - a[n - 1];
            max_sum = max(m1, m2);
        }
        if (max_sum < sum) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}