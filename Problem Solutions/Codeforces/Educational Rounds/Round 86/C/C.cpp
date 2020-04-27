#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    ll a, b, q;
    cin >> a >> b >> q;

    vector<ll> cnt(a*b + 1, 0);
    // the values will repeat after a*b for sure
    // we count the prefix sum of required values till in [1, ab]
    for (int i = 1; i <= a*b; ++i) {
        if (((i % a) % b) != ((i % b) % a)) {
            ++cnt[i];
        }
        cnt[i] = cnt[i - 1] + cnt[i];
    }

    ll l, r;
    ll res = 0;
    ll p = a*b;
    ll left, right;
    ll right_remain, left_remain;
    for (int i = 0; i < q; ++i) {
        cin >> l >> r;

        // find count[r] - count[l - 1]
        // these many full ranges of an interval [1, ab] will come
        left = (l - 1)/p;
        right = r/p;
        res += (right - left)*cnt[p];

        // what remains, we can map it to [1, ab] interval
        right_remain = r % p;
        left_remain = (l - 1) % p;

        res += cnt[right_remain] - cnt[left_remain];
        cout << res << " ";
        res = 0;
    }
    cout << endl;
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