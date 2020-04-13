#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

const int MAX = 26;
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x: arr) {
        cin >> x;
    }

    vector<int> cnt[MAX + 1];
    vector<int> total(MAX + 1, 0);
    for (int cur = 1; cur <= MAX; ++cur) {
        int cur_cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] == cur) {
                ++cur_cnt;
            }
            cnt[cur].push_back(cur_cnt);
        }
        total[cur] = cur_cnt;
    }

    // mid element
    int res = 0;
    for (int mid = 1; mid <= MAX; ++mid) {
        for (int other = 1; other <= MAX; ++other) {
            int total_cnt = total[other];
            int left_cnt;
            int right_cnt;
            for (int i = 0; i < n; ++i) {
                left_cnt = cnt[other][i];
                int mid_cnt = 0;
                for (int j = i + 1; j < n; ++j) {
                    if (arr[j] == mid) {
                        ++mid_cnt;
                    }
                    right_cnt = total_cnt - cnt[other][j];
                    res = max(res, 2*min(left_cnt, right_cnt) + mid_cnt);
                }
                res = max(res, left_cnt);
            }
        }
    }
    cout << res << endl;
}

int main() {
    FAST_IO

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}