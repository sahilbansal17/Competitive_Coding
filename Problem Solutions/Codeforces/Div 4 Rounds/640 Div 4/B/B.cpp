#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    ll n, k;
    cin >> n >> k;

    ll rem = n % k;
    ll res = n/k;

    bool orem = rem & 1;
    bool ores = res & 1;

    if (k > n) {
        cout << "NO" << endl;
        return;
    }
    if (!orem) {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; ++i) {
            cout << res << " ";
        }
        cout << res + rem << endl;
    } else {
        if (k & 1) {
            if (k >= 2 && res - 1 == 0) {
                cout << "NO" << endl;
                return;
            }
            cout << "YES" << endl;
            for (int i = 0; i < k/2; ++i) {
                cout << res - 1 << " " << res + 1 << " ";
            }
            cout << res + rem << endl;
        } else {
            cout << "NO" << endl;
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