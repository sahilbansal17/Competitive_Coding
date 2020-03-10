#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool check(vector<ll>& a, vector<ll> &b) {
    int x1 = a[0];
    int y1 = b[0];
    int x2 = a[1];
    int y2 = b[1];
    int dx = x2 - x1;
    int dy = y2 - y1;
    int d = gcd(abs(dx), abs(dy));
    dx /= d;
    dy /= d;

    int cx = dx;
    int cy = dy;
    bool poss = true;
    int n = a.size();
    for (int i = 2; i < n; ++i) {
        x2 = a[i];
        y2 = b[i];
        dx = x2 - x1;
        dy = y2 - y1;
        d = gcd(abs(dx), abs(dy));
        dx /= d;
        dy /= d;
        if (cx != dx || cy != dy) {
            poss = false;
        }
    }
    return poss;
}
int main() {

    FAST_IO;
    
    ll t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<ll> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        int res = 0;
        bool poss = check(a, b);
        if (poss) {
            ++res;
        }
        reverse(b.begin(), b.end());
        poss = check(a, b);
        if (poss) {
            ++res;
        }

        cout << res << endl;
    }

    return 0;
}