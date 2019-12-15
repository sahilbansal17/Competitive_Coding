#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int res = 0, cnt;
    if (e > f) {
        cnt = min(a, d);
        res += min(a, d) * e;
        a -= cnt;
        d -= cnt;
        res += min(b, min(c, d)) * f;
    } else {
        cnt = min(b, min(c, d));
        res += min(b, min(c, d)) * f;
        b -= cnt;
        c -= cnt;
        d -= cnt;
        res += min(a, d) * e;
    }
    cout << res << endl;
    return 0;
}