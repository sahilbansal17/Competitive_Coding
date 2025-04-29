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

    for (int i = 0; i < t; ++i) {
        string s;
        int n;
        cin >> n;

        cin >> s;

        if (s[0] == 'B' && s[n - 1] == 'B') {
            cout << "Bob" << endl;
            continue;
        }
        if (s[0] == 'A' && s[n - 1] == 'A') {
            cout << "Alice" << endl;
            continue;
        }
        if (s[0] == 'B' && s[n - 1] == 'A') {
            if (s[n - 2] == 'B') {
                cout << "Bob" << endl;
            } else {
                cout << "Alice" << endl;
            }
            continue;
        }

        int cntB = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] == 'B') {
                ++cntB;
            }
        }
        if (cntB >= 2) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
    }

    return 0;
}
