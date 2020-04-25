#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7;

const int MAX = 1e6 + 10;
void solve() {
    int n, q, x, l, r, y;
    cin >> n >> q;

    vector<pair<int, int>> pts, queries;
    vector<int> cnt(MAX, 0);
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        pts.push_back({x, y});
    }

    for (int i = 0; i < q; ++i) {
        cin >> l >> r;
        queries.push_back({l, r});
    }
    
    int gap = queries[0].second - queries[0].first;
    int left, right;
    for (int i = 0; i < n; ++i) {
        x = pts[i].first;
        y = pts[i].second;
        if (y > gap/2) {
            continue;
        }
        if (y > x) {
            continue;
        }
        if (x + y - gap >= MAX) {
            continue;
        }
        left = max(0, x + y - gap);
        right = min(MAX - 2, x - y + 1);
        ++cnt[left];
        --cnt[right];

    }

    for (int i = 1; i < MAX; ++i) {
        cnt[i] += cnt[i - 1];
    }

    for (int i = 0; i < q; ++i) {
        left = queries[i].first;
        cout << cnt[left] << " ";
    }
    cout << endl;
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