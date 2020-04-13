#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

#define endl '\n'
void solve() {
    int n;
    cin >> n;

    int res = ceil(1.0*(n - 3)/2) + 1;
    if (n <= 3) {
        res = 1;
    }
    cout << res << endl;
    if (n <= 3) {
        cout << n << " ";
    } else {
        cout << 3 << " ";
    }
    int cur = 1;
    for (int i = 0; i < min(n, 3); ++i) {
        cout << cur << " ";
        ++cur;
    }
    cout << endl;
    
    while (cur <= n) {
        if (cur == n) {
            cout << 1 << " " << cur << endl;
            cur += 1;
        } else {
            cout << 2 << " " << cur << " " << cur + 1 << endl;
            cur += 2;
        }
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