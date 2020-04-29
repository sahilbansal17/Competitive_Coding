#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    map<int, int> done;
    int maxcnt = 0;
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        int cur = a[i];
        if (done.find(cur) != done.end()) {
            continue;
        }
        int prev = i;
        int cnt = 1;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] == cur && prev != j - 1) {
                ++cnt;
                prev = j;
            }
        }
        done[cur] = 1;
        if (cnt > maxcnt) {
            ans = cur;
            maxcnt = cnt;
        } else if (cnt == maxcnt && cur < ans) {
            ans = cur;
        }
    }
    cout << ans << endl;
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