#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

template <typename T> T power(T x, T y, ll m = MOD) {
    T ans = 1;
    x %= m;
    while (y > 0) {
        if (y & 1LL) {
            ans = (ans * x) % m;
        }
        y >>= 1LL;
        x = (x * x) % m;
    }
    return (ans % m);
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;

    ll t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int prev = -2;
        int x;
        int diff = -2;
        bool res = true;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (prev != -2) {
                diff = abs(x - prev);
            }

            if (diff != -2 && diff != 5 && diff != 7) {
                res = false;
            }

            prev = x;
        }

        if (res) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
