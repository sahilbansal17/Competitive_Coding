#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int x, n, m;
    cin >> x >> n >> m;

    while (x > 20 && n > 0) {
        x = x/2 + 10;
        --n;
    }
    while (m > 0) {
        x -= 10;
        --m;
    }
    // cerr << x << endl;
    if (x <= 0) {
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