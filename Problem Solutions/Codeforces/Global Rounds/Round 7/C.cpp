#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

const ll MOD = 998244353;
int main() {
    FAST_IO;
    
    ll n, k;
    cin >> n >> k;
    
    vector<ll> p(n), pos;
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        if (p[i] > n - k) {
            res += p[i];
            pos.push_back(i);
        }
    }

    ll times = 1;
    for (int i = 0; i < pos.size() - 1; ++i) {
        times *= (pos[i + 1] - pos[i]);
        times %= MOD;
    }
    cout << res << " " << times << endl;

    return 0;
}