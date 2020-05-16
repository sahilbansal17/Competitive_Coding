#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

const int MAXN = 1e6 + 10;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    vector<ll> cnt(MAXN, 0);
    ll left, right;
    for (ll i = a; i <= b; ++i) {
        left = i + b;
        right = i + c;
        ++cnt[left];
        --cnt[right + 1];
    }
    for (int i = 1; i < MAXN; ++i) {
        cnt[i] += cnt[i - 1];
    }

    for (int i = MAXN - 2; i >= 0; --i) {
        cnt[i] += cnt[i + 1];
    }

    ll res = 0;
    for (int i = c; i <= d; ++i) {
        res += cnt[i + 1];
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