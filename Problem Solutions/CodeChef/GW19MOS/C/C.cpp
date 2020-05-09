#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> h(n, vector<int> (n));
    vector<pair<int, int>> pos[k + 1];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> h[i][j];
            pos[h[i][j]].push_back({i, j});
        }
    }

    vector<vector<int>> cost(n, vector<int> (n, 0));
    int res = INT_MAX;
    if (k == 1) {
        res = 0;
    }
    for (int val = 2; val <= k; ++val) {
        for (auto cur: pos[val]) {
            int i = cur.first;
            int j = cur.second;
            int curcost = INT_MAX;
            for (auto prev: pos[val - 1]) {
                int k = prev.first;
                int l = prev.second;
                curcost = min(curcost, cost[k][l] + abs(i - k) + abs(j - l));
            }
            cost[i][j] = curcost;
            if (val == k) {
                res = min(res, curcost);
            }
        }
    }
    /*/
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    //*/
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