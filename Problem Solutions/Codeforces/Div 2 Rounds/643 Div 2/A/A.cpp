#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

ll next(ll n) {
    ll res = 0;
    ll mini = 10;
    ll maxi = 0;
    while (n) {
        ll c = n % 10;
        if (c > maxi) {
            maxi = c;
        }
        if (c < mini) {
            mini = c;
        }
        n /= 10;
    }
    return mini*maxi;
}

bool zero(ll n) {
    bool poss = false;
    while (n) {
        ll c = n % 10;
        if (c == 0) {
            poss = true;
        }
        n /= 10;
    }
    return poss;
}
void solve() {

    ll n, k;
    cin >> n >> k;

    int c = 1;
    while (c < k && !zero(n)) {
        n += next(n);
        ++c;
    }
    cout << n << endl;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}