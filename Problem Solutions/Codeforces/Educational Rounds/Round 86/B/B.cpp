#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    string t;
    cin >> t;

    int c0 = 0;
    int n = t.length();
    for (int i = 0; i < n; ++i) {
        if (t[i] == '0') {
            ++c0;
        }
    }
    if (c0 == 0 || c0 == n) {
        int res = 1;
        if (c0 == n) {
            res = 0;
        }
        for (int i = 0; i < n; ++i) {
            cout << res;
        }
    } else {
        for (int i = 0; i < 2*n; ++i) {
            if (i & 1) {
                cout << '1';
            } else {
                cout << '0';
            }
        }
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