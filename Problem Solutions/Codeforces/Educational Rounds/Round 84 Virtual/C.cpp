#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> start_pos(k), visit_pos(k);
    for (int i = 0; i < k; ++i) {
        cin >> start_pos[i].first >> start_pos[i].second;
    }
    for (int i = 0; i < k; ++i) {
        cin >> visit_pos[i].first >> visit_pos[i].second;
    }

    // following the greedy and constructive approach as mentioned in editorial
    int res = n*m + n + m - 3;
    cout << res << endl;
    for (int i = 0; i < n - 1; ++i) {
        cout << 'U';
    }
    for (int i = 0; i < m - 1; ++i) {
        cout << 'L';
    }
    for (int i = 0; i < n; ++i) {
        if (i & 1) {
            for (int i = 0; i < m - 1; ++i) {
                cout << 'L';
            }
        } else {
            for (int i = 0; i < m - 1; ++i) {
                cout << 'R';
            }
        }
        if (i != n - 1) {
            cout << 'D';
        }
    }
    cout << endl;
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