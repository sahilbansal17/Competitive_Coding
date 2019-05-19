#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

ll solve (ll l, ll r, ll g) {

    ll st = l/g;
    ll en = r/g;

    if (st*g < l) {
        st ++;
    }
    
    ll res = (en - st + 1);
    if (res == 1) {
        if (g < l || g > r) {
            return 0;
        }
    }
    return res;
}

int main() {

    FAST_IO;    

    ll t;
    cin >> t;

    while (t --) {
        ll l, r, g;
        cin >> l >> r >> g;
        cout << solve(l, r, g) << endl;
    }

    return 0;
}