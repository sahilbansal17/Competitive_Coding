#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int n;
vector<ll> a;

int main() {
    FAST_IO;

    cin >> n;
    a.resize(n);
    ll sum = 0;
    for (auto &x: a) {
        cin >> x;
        sum += x;
    }

    if (sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll u = sum/3;
    ll v = 2*sum/3;
    ll ans = 0;
    ll cnt = 0;
    ll cur_sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        cur_sum += a[i];
        if (cur_sum == v) {
            ans += cnt;
        }
        if (cur_sum == u) {
            ++cnt;
        }
    }
    cout << ans << endl;
    return 0;
}