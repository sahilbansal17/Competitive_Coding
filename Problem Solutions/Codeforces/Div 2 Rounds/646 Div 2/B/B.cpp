#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    string s;
    cin >> s;

    int n = s.length();
    int res = 1001;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            ++c0;
        } else {
            ++c1;
        }
    }
    int cur0 = 0, cur1 = 0;
    res = min(c0, c1);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            ++cur0;
        } else {
            ++cur1;
        }
        res = min(res, cur1 + (c0 - cur0));
        res = min(res, cur0 + (c1 - cur1));
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