/**
 * Gives WA on test set 1
 * Need to figure out the mistake
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n, d;
    cin >> n >> d;

    vector<ll> v(n);
    map<ll, ll> cnt;
    for (auto &x: v) {
        cin >> x;
        ++cnt[x];
    }

    for (int i = 0; i < n; ++i) {
        if (cnt[v[i]] >= d) {
            cout << 0 << endl;
            return;
        }
    }

    if (d == 2) {
        cout << 1 << endl;
        return;
    }
    
    // d = 3

    for (int i = 0; i < n; ++i) {
        if (cnt[2*v[i]] >= 1) {
            cout << 1 << endl;
            return;
        }
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < n - 1; ++i) {
        if (cnt[v[i]] >= 2) {
            cout << 1 << endl;
            return;
        }
    }

    cout << 2 << endl;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}