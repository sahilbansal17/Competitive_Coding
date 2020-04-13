#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int x, k;
    cin >> x >> k;

    int cnt = 0;
    int cur = 2;
    int limit = sqrt(x);
    while (x > 1 && cur <= limit) {
        while (x % cur == 0) {
            x /= cur;
            ++cnt;
        }
        ++cur;
    }
    if (x > 1) {
        ++cnt;
    }
    if (cnt >= k) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
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