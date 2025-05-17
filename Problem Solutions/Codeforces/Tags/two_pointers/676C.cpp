#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

template <typename T> T power(T x, T y, ll m = MOD) {
    ll ans = 1;
    x %= m;
    while (y > 0) {
        if (y & 1LL) {
            ans = (ans * x) % m;
        }
        y >>= 1LL;
        x = (ll)x * x % m;
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int max_beauty = 0;
    int count_a = 0, count_b = 0;
    int l = 0;

    for (int r = 0; r < n; ++r) {
        if (s[r] == 'a') {
            count_a++;
        } else {
            count_b++;
        }

        while (min(count_a, count_b) > k) {
            if (s[l] == 'a') {
                count_a--;
            } else {
                count_b--;
            }
            l++;
        }

        max_beauty = max(max_beauty, r - l + 1);
    }
    cout << max_beauty << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}