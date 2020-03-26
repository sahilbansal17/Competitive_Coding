#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

ll sum(ll cur) {
    ll sum = (cur * (cur + 1))/2;
    return sum;
}

void solve(ll n, ll k) {
    // find first 'n' where sum(n) > k
    ll low = 1, high = n;
    ll mid;
    while (low < high) {
        mid = low + ((high - low)/2);
        ll s = sum(mid);
        if (s >= k) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    ll s = sum(low);
    // ll ans;
    ll first, second; // denote the bits where '1' or 'b' will be there
    if (s == k) {
        first = low;
        second = low - 1;
        // ans = pow(2, low) + pow(2, low - 1);
    } else {
        ll prev = sum(low - 1);
        ll rem = k - prev;
        // ans = pow(2, low) + pow(2, rem - 1);
        first = low;
        second = rem - 1;
    }

    for (int i = n - 1; i >= 0; --i) {
        if (i == first || i == second) {
            cout << 'b';
        } else {
            cout << 'a';
        }
    }
    cout << endl;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin >> n >> k;
        solve(n, k);
    }

    return 0;
}