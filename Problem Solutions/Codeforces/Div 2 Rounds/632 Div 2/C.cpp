#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

int main() {
    FAST_IO;

    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }
    
    // unordered_map<ll, ll> prev_idx;
    map<ll, ll> prev_idx;
    prev_idx[0] = -1;
    ll cur_sum = 0;
    ll res = 0;
    ll prev = -1;
    for (ll i = 0; i < n; ++i) {
        cur_sum += a[i];
        if (prev_idx.find(cur_sum) != prev_idx.end()) {
            if (prev == -1) {
                res += (i) - (prev_idx[cur_sum] + 1);
            } else {
                res += (i) - max(prev, prev_idx[cur_sum] + 1);
            }
            prev = max(prev, prev_idx[cur_sum] + 1);
        } else {
            if (prev == -1) {
                res += i + 1;
            } else {
                res += i - prev;
            }
        }
        prev_idx[cur_sum] = i;
    }
    cout << res << endl;
    return 0;
}