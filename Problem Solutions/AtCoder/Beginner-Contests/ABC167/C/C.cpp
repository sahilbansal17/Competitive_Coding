#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

int n, m, x;
int res;

void rec_solve(int cur, int cost, vector<pair<int, vector<int>>>& books, vector<int> levels) {
    if (cur == books.size()) {
        for (int i = 0; i < m; ++i) {
            if (levels[i] < x) {
                return;
            }
        }
        res = min(res, cost);
        return;
    }
    // don't pick the book
    rec_solve(cur + 1, cost, books, levels);
    // pick the book
    for (int i = 0; i < m; ++i) {
        levels[i] += books[cur].second[i];
    }
    rec_solve(cur + 1, cost + books[cur].first, books, levels);
}

void solve() {
    cin >> n >> m >> x;

    int c;
    vector<pair<int, vector<int>>> books;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        vector<int> level(m);
        for (auto &l: level) {
            cin >> l;
        }
        books.push_back({c, level});
    }

    res = INT_MAX;
    vector<int> levels(m, 0);
    rec_solve(0, 0, books, levels);
    
    if (res == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
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