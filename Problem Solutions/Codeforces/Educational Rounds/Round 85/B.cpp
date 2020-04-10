#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve() {
    ll n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for (auto &p: a) {
        cin >> p;
    }
    sort(a.begin(), a.end());
    ll cur = 0;
    int res = 0;
    for (int i = n - 1; i >= 0; --i) {
        cur += a[i];
        if (cur/(res + 1) >= x) {
            ++res;
        } else {
            break;
        }
    }
    cout << res << endl;
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