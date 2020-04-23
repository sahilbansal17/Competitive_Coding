#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'
const int MAX = 2e5 + 10;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> pref(2*k + 2, 0), cnt(2*k + 1, 0);
    for (auto &x: a) {
        cin >> x;
    }

    for (int i = 0; i < n/2; ++i) {
        int mn = min(a[i], a[n - i - 1]);
        int mx = max(a[i], a[n - i - 1]);
        int sum = mn + mx;
        ++pref[mn + 1];
        --pref[mx + k + 1];
        ++cnt[a[i] + a[n - i - 1]];
    }
    for (int i = 1; i <= 2*k + 1; ++i) {
        pref[i] += pref[i - 1];
    }

    int res = n;
    for (int i = 2; i <= 2*k; ++i) {
        res = min(res, (pref[i] - cnt[i]) + (n/2 - pref[i])*2 );
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