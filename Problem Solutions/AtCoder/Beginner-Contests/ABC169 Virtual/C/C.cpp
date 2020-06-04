#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
// #define MULTIPLE_TESTS 1

void solve() {
    ll a;
    double b;
    cin >> a >> b;
    ll res = round(b*100);
    res *= a;
    res /= 100;
    cout << res << endl;
}

int main() {
    FAST_IO;
    int t = 1;
    #ifdef MULTIPLE_TESTS
    cin >> t;
    #endif

    while (t--) {
        solve();
    }
    return 0;
}