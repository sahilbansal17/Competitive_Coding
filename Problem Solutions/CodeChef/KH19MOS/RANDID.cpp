#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

void solve() {
    int n, q;
    cin >> n >> q;

    double res = n + q - n/(q + 1.);
    cout << fixed;
    cout << setprecision(9) << res << endl;
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