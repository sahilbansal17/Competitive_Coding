#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    ll X;
    cin >> X;

    ll cur = 100;
    for (int i = 1; i <= 3760; ++i) {
        cur *= 1.01;
        if (cur >= X) {
            cout << i << endl;
            break;
        }
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