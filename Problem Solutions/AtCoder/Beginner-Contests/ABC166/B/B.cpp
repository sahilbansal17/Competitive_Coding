#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;

    int d;
    vector<int> cnt(n, 0);
    int x;
    for (int i = 0; i < k; ++i) {
        cin >> d;
        for (int j = 0; j < d; ++j) {
            cin >> x;
            ++cnt[x-1];
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 0) {
            ++res;
        }
    }
    cout << res << endl;
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