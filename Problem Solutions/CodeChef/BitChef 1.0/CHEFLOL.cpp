#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;
    
    int t;
    cin >> t;

    int n;
    while (t --) {
        cin >> n;
        ll res = 0;
        ll x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x > 0) {
                res += x;
            }
        }
        cout << res << endl;
    }
    return 0;
}