#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    ll res = 0;
    map<ll, ll> cnt;
    for (int i = 0; i < n; ++i) {
        ll cur = i - a[i];
        res += cnt[cur];
        ++cnt[i + a[i]];
    }
    cout << res << endl;

}

int main() {
    FAST_IO;

    int t;
    // cin >> t;
    t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}