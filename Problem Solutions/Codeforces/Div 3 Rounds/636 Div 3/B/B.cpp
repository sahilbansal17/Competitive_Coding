#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    if (n % 4 == 0) {
        cout << "YES" << endl;
        int x = 2;
        for (int i = 1; i <= n/2; ++i) {
            cout << x << " ";
            x += 4;
        }
        int k = 3;
        for (int i = 1; i <= n/4; ++i) {
            cout << k << " " << k + 2 << " ";
            k += 8;
        }
        cout << endl;
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