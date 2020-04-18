#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    ll total = (1ll*n*(n + 1))/2;
    ll subt = 0; // to be subtracted, containing one even factor

    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 4 == 2 || a[i] % 4 == -2) {
            pos.push_back(i);
        } else if (a[i] % 4 == 0) {
            pos.push_back(i);
        }
    }
    int k = pos.size();
    int left = -1;
    int right;
    for (int i = 0; i < k; ++i) {
        ll cur = pos[i];
        if (a[cur] % 4 == 0) {
            left = cur;
            continue;
        }
        if (i != k - 1) {
            right = pos[i + 1];
        } else {
            right = n;
        }
        // cout << left << " " << cur << " " << right << endl;
        subt += 1ll * (cur - left) * (right - cur);
        left = cur;
    }
    cout << total - subt << endl;
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