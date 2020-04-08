#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;

    cout << 'W';
    for (int i = 1; i < m; ++i) {
        cout << 'B';
    }
    cout << endl;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << 'B';
        }
        cout << endl;
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