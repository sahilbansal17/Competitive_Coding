#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int k, a, b;
    cin >> k;
    cin >> a >> b;

    int d1 = a/k;
    int d2 = b/k;

    // cout << d1 << " " << d2 << endl;
    if (d1 == d2) {
        if (a % k == 0 || b % k == 0) {
            cout << "OK";
        } else {
            cout << "NG";
        }
    } else {
        cout << "OK";
    }
    cout << endl;
 
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