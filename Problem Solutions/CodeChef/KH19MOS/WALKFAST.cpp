#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

int main() {

    FAST_IO;

    int t;
    cin >> t;

    int n, a, b, c, d, p, q, y;
    while (t--) {
        cin >> n >> a >> b >> c >> d >> p >> q >> y;

        vector<int> x(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> x[i];
        }

        int cost1 = abs(x[b] - x[a]) * p;
        if (abs(x[c] - x[a]) * p <= y) {
            int cost2 = y + (abs(x[c] - x[d]) * q) + (abs(x[d] - x[b]) * p);
            if (cost2 < cost1) {
                cout << cost2 << endl;
                continue;
            }
        }
        cout << cost1 << endl;
    }
    
    return 0;
}