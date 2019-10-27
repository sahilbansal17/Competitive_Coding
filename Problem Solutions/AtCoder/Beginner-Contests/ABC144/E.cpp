#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

bool possible(ll mid, ll k, vector<pair<ll, int> > a) {
    ll req = 0;
    int n = a.size();
    for (int i = 0; i < n; ++i) {
        if (a[i].first > mid) {
            req += ceil((1.0*(a[i].first - mid))/a[i].second);
        }
    }
    if (req <= k) {
        return 1;
    }
    return 0;
}

int main() {
    FAST_IO;
    
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n), f(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }

    sort(a.begin(), a.end());
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());

    vector<pair<ll, int> > prod;
    for (int i = 0; i < n; ++i) {
        prod.push_back(make_pair(a[i]*f[i], f[i]));
    }
    
    ll low = 0;
    ll high = 1e12;
    ll mid;
    while (low < high) {
        mid = low + ((high - low)>>1);
        if (possible(mid, k, prod)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    cout << low << endl;
    return 0;
}