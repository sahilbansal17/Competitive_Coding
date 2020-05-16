#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n, s;
    cin >> n >> s;

    int maxi = s - (n - 1);
    if (n <= maxi - 1) {
        cout << "YES" << endl;
        for (int i = 0; i < n - 1; ++i) {
            cout << 1 << " ";
        }
        cout << maxi << endl;
        cout << n << endl;
    } else {
        cout << "NO" << endl;
    }
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