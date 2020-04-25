#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<pair<int, int>> q;
    int l, r;
    for (int i = 0; i < n; ++i) {
        cin >> l >> r;
        q.push_back({l, r});
    }

    vector<ll> pre(n);
    for (int i = 1; i < k; ++i) {
        pre[0] = a[0];
        for (int j = 1; j < n; ++j) {
            pre[j] = pre[j - 1] ^ a[j];
        }

        for (int j = 0; j < n; ++j) {
            l = q[j].first - 1;
            r = q[j].second - 1;
            a[j] = pre[r];
            if (l - 1 >= 0) {
                a[j] ^= pre[l - 1];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}