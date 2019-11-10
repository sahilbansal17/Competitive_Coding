#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;
    int q;
    cin >> q;

    ll a, b, n, s;
    while (q--) {
        cin >> a >> b >> n >> s;

        ll req = s/n;
        ll used = min(req, a);
        ll res = used*n;
        ll rem = s - res;
        if (rem <= b) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}