#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    set<int> s;
    vector<pair<int, int>> pos;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (s.find(x) == s.end()) {
            s.insert(x);
        }
        pos.push_back({x, i});
    }
    sort(pos.begin(), pos.end());
    int res = 1;
    int tot = s.size();
    int prev = -1;

    int i = 0;
    while (i < n) {
        int cur = pos[i].second;
        int val = pos[i].first;
        int minId = n + 1;
        int lastpos = n + 1;
        while (i < n && pos[i].first == val) {
            int id = pos[i].second;
            if (id > prev && id < minId) {
                minId = id;
            }
            lastpos = min(lastpos, id);
            ++i;
        }
        if (minId == n + 1) {
            ++res;
            prev = lastpos;
        } else {
            prev = minId;
        }
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