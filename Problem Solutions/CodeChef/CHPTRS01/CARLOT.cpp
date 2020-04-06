#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve() {
    int m, n;
    cin >> m >> n;

    vector<vector<char>> grid(m, vector<char>(n));

    vector<pair<int, pair<int, int>>> parkings;
    for (int i = 0; i < m; ++i) {
        int start = -1;
        int end = -1;
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'P') {
                if (start == -1) {
                    start = j;
                }
                if (j > end) {
                    end = j;
                }
            }
        }
        if (start != -1) {
            parkings.push_back({i, {start, end}});
        }
    }

    int total = parkings.size();
    int res = 0;
    int prev_start = -1, prev_end = -1, prev_level = -1;

    // cout << endl;
    for (int cur = 0; cur < total; ++cur) {
        int level = parkings[cur].first;
        int start = parkings[cur].second.first;
        int end = parkings[cur].second.second;

        // cout << level << " " << start << " " << end << endl;
        res += end - start;

        if (prev_level != -1) {
            if (level % 2 == 1 && prev_level % 2 == 0) {
                // need to go right
                res += abs(end - prev_end);
            } else if (level % 2 == 0 && prev_level % 2 == 1) {
                // need to go left
                res += abs(prev_start - start);
            } else if (level % 2 == 0 && prev_level % 2 == 0) {
                res += abs(prev_end - start);
            } else {
                // level and prev_level both have odd parity
                res += abs(prev_start - end);
            }
            res += (level - prev_level);
        }

        prev_start = start;
        prev_end = end;
        prev_level = level;
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