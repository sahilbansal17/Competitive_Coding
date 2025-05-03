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

    ll t = 1;

    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;

        vector<vector<int>> mat(n, vector<int>(k, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                cin >> mat[i][j];

                if (i > 0) {
                    mat[i][j] |= mat[i - 1][j];
                }
            }
        }

        int m;
        int r, c;
        char o;

        while (q--) {
            vector<vector<int>> bounds(k + 1, vector<int>(2, -1));

            cin >> m;

            while (m--) {
                cin >> r;
                cin >> o;
                cin >> c;

                if (o == '>') {
                    if (bounds[r - 1][0] == -1) {
                        bounds[r - 1][0] = c;
                    } else {
                        bounds[r - 1][0] = max(bounds[r - 1][0], c);
                    }
                } else {
                    if (bounds[r - 1][1] == -1) {
                        bounds[r - 1][1] = c;
                    } else {
                        bounds[r - 1][1] = min(bounds[r - 1][1], c);
                    }
                }
            }

            int country = 0;
            int region = 0;
            int low = 0, high = n - 1;
            while (low <= high && region < k) {
                if (bounds[region][0] == -1 && bounds[region][1] == -1) {
                    ++region;
                    continue;
                }

                int mini = bounds[region][0] == -1 ? 0 : bounds[region][0];
                int maxi = bounds[region][1] == -1 ? INT_MAX : bounds[region][1];

                // cerr << country << " " << region << " " << mini << " " << maxi << endl;
                if (mat[country][region] > mini && mat[country][region] < maxi) {
                    ++region;
                    continue;
                }
                if (mat[country][region] <= mini) {
                    low = country + 1;
                    ++country;
                    continue;
                }
                if (mat[country][region] >= maxi) {
                    high = country - 1;
                    --country;
                    continue;
                }
            }
            // cerr << endl << endl;
            if (country < 0 || country >= n || region < k) {
                cout << -1 << endl;
            } else {
                cout << country + 1 << endl;
            }
        }
    }

    return 0;
}
