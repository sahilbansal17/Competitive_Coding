#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> cnt(n + 1, 0);
    int distinct = 0;
    for (auto &a: arr) {
        cin >> a;
        ++cnt[a];
        if (cnt[a] == 1) {
            ++distinct;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        int cur = cnt[i];
        res = max(res, max(min(cur, distinct - 1), min(cur - 1, distinct)));
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