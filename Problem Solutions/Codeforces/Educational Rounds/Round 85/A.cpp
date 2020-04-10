#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    int p, c;
    int x = -1, y = -1;
    bool res = true;
    for (int i = 0; i < n; ++i) {
        cin >> p >> c;
        if (c > p) {
            res = false;
        }
        if (x == -1 && y == -1) {
            x = p;
            y = c;
            continue;
        }
        if (p - x < 0 || c - y < 0) {
            res = false;
        }else if (p - x < c - y) {
            res = false;
        }
        
        x = p;
        y = c;
    }
    if (res) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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