#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'
#define TESTCASES 1

void solve() {
    
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    ll x = x2 - x1;
    ll y = y2 - y1;

    ll times = max(x, y) - min(x, y) + 1;
    ll mn = min(x, y);
    ll res = mn*times;

    res += (mn - 1)*mn;
    res += 1;
    cout << res << endl;
}

int mat[5][5] = { {1, 2, 4, 7, 11}, {3, 5, 8, 12, 17}, {6, 9, 13, 18, 24}, {10, 14, 19, 25, 32}, {15, 20, 26, 33, 41}};
set<int> dist;

void find(int x, int y, int dx, int dy, int cur) {
    if (x == dx && y == dy) {
        dist.insert(cur + mat[dx][dy]);
    }
    if (x > dx || y > dy) {
        return;
    }
    find(x, y + 1, dx, dy, cur + mat[x][y]);
    find(x + 1, y, dx, dy, cur + mat[x][y]);
}
void compute() {
    find(0, 0, 1, 3, 0);
    cout << dist.size() << endl;
    for (auto x: dist) {
        cout << x << " ";
    }
}

int32_t main() {
    FAST_IO;

    int t;
    #ifdef TESTCASES
    cin >> t;
    #endif

    #ifndef TESTCASES
    t = 1;
    #endif

    while (t--) {
        solve();
    }

    // compute();
    return 0;
}