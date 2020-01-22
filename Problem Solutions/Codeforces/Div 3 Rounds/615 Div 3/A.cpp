#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        ll a, b, c, n;
        cin >> a >> b >> c >> n;

        ll sum = a + b + c + n;
        if (sum % 3 != 0) {
            cout << "NO" << endl;
        } else {
            ll fac = sum/3;
            if (fac >= a && fac >= b && fac >= c) {
                ll rem = (fac - a) + (fac - b) + (fac - c);
                if (rem == n) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}