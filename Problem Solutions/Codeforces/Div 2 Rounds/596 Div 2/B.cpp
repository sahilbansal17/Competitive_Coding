#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
void solve() {
    int n, k, d;
    cin >> n >> k >> d;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = d, cur = 0, val, last;
    unordered_map<int, int> cnt;
    for (int i = 0; i < d; ++i) {
        val = a[i];
        if (cnt[val] != 0) {
            ++cnt[val];
        }  else {
            cnt[val] = 1;
            ++cur;
        }
    }
    if (cur < res) {
        res = cur;
    }
    for (int k = d; k < n; ++k) {
        val = a[k];
        if (cnt[val] != 0) {
            ++cnt[val];
        } else {
            cnt[val] = 1;
            ++cur;
        }
        last = a[k - d];
        if (cnt[last] == 1) {
            cnt[last] = 0;
            --cur;
        } else {
            --cnt[last];
        }
        if (cur < res) {
            res = cur;
        }
    }
    cout << res << endl;
}
int main() {
    FAST_IO;
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}