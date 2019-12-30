#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int max1 = 0, max2 = 0;
        int x;
        for (int i = 0; i < k1; ++i) {
            cin >> x;
            if (x >= max1) {
                max1 = x;
            }
        }

        for (int i = 0; i < k2; ++i) {
            cin >> x;
            if (x >= max2) {
                max2 = x;
            }
        }

        if (max1 > max2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}