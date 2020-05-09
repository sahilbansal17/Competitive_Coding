#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

ll check(ll v, ll n) {
    ll c = v - v/n;
    return c;
}
void solve() {
    ll n, k;
    cin >> n >> k;

    ll low = 1, high = 1e18;
    ll mid;
    while (low < high) {
        mid = low + (high - low)/2;
        ll c = check(mid, n);
        if (c < k) {
            low = mid;
        } else if (c > k) {
            high = mid;
        } else {
            if (mid % n == 0) {
                cout << mid - 1 << endl;
            } else {
                cout << mid << endl;
            }
            return ;
        }
    }
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