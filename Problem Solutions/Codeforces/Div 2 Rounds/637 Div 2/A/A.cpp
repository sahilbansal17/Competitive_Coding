#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        ll n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;

        ll mini = n*(a - b);
        ll maxi = n*(a + b);

        ll mi = c - d;
        ll ma = c + d;

        ll A = max(mini, mi);
        ll B = min(maxi, ma);
        if (B >= A) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}