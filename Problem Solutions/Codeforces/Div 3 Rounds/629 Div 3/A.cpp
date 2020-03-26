#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    ll a, b;
    ll res;
    while (t--) {
        cin >> a >> b;

        if (a % b == 0) {
            cout << 0 << endl;
        } else {
            res = b*(a/b + 1) - a;
            cout << res << endl;
        }
    }

    return 0;
}