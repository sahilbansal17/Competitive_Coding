#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto &x: a) {
        cin >> x;
    }
    for (auto &y: b) {
        cin >> y;
    }

    bool one = false, neg = false;
    for (int i = 0; i < n; ++i) {
        if (b[i] > a[i] && !one) {
            cout << "NO" << endl;
            return;
        }
        if (b[i] < a[i] && !neg) {
            cout << "NO" << endl;
            return;
        }
        if (a[i] == 1) {
            one = true;
        } else if (a[i] == -1) {
            neg = true;
        }
    }
    cout << "YES" << endl;
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