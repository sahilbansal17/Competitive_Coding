#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;
    
    ll a, b;
    while (t--) {
        cin >> a >> b;

        ll cur = 9;
        ll res = 0;
        while (cur <= b) {
            res += a;
            cur = cur*10 + 9;
        }

        cout << res << endl;
    }

    return 0;
}