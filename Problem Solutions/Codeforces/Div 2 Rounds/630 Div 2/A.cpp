#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        ll x, y, x1, y1, x2, y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;

        ll xx = x + (b - a);
        ll yy = y + (d - c);
        
        if (xx < x1 || xx > x2 || yy < y1 || yy > y2) {
            cout << "NO" << endl;
        } else {
            if (x == x1 && x == x2 && (b > 0 || a > 0)) {
                cout << "NO" << endl;
            } else if (y == y1 && y == y2 && (c > 0 || d > 0)) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}