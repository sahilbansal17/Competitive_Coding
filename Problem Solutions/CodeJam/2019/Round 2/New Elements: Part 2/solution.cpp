/**
 * Passes test set 1
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7;
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> vp;
    int x, y;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        vp.push_back({x, y});
    }
    bool done = false;
    for (int c = 1; c <= 10000; ++c) {
        for (int j = 1; j <= 10000; ++j) {
            int cur = 0;
            int prev = -1;
            bool possible = true;
            for (int k = 0; k < n; ++k) {
                cur = vp[k].first * c + vp[k].second * j;
                if (cur <= prev) {
                    possible = false;
                    break;
                }
                prev = cur;
            }
            if (possible) {
                cout << c << " " << j << endl;
                done = true;
                break;
            }
        }
        if (done) {
            break;
        }
    }
    if (!done) {
        cout << "IMPOSSIBLE" << endl;
    }
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    for (int id = 1; id <= t; ++id) {
        cout << "Case #" << id << ": ";
        solve();
    }
    
    return 0;
}