#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    vector<int> peak(n, 0);
    for (int i = 1; i < n - 1; ++i) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            ++peak[i];
        }
    }
    for (int i = 1; i < n; ++i) {
        peak[i] = peak[i - 1] + peak[i];
    }

    int maxcnt = 0;
    int l = 0;
    for (int i = 0; i < n; ++i) {
        int end = i + k - 2;
        if (end >= n) {
            break;
        }
        int cnt = peak[end] - peak[i];
        if (cnt > maxcnt) {
            maxcnt = cnt;
            l = i;
        }
    }
    cout << maxcnt + 1 << " " << l + 1 << endl;
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