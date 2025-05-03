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
        string s;
        cin >> s;

        int q;
        cin >> q;

        unordered_set<int> indices;
        for (int i = 0; i < s.length() - 3; ++i) {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') {
                indices.insert(i);
            }
        }

        int i;
        char v;
        int n = s.length();
        while (q--) {
            cin >> i >> v;

            i--;
            s[i] = v;
            indices.erase(i);
            int j = i;
            if (j + 3 <= n - 1 && s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0') {
                indices.insert(i);
            }

            if (i - 1 >= 0) {
                indices.erase(i - 1);

                j = i - 1;
                if (j + 3 <= n - 1 && s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0') {
                    indices.insert(j);
                }
            }
            if (i - 2 >= 0) {
                indices.erase(i - 2);

                j = i - 2;
                if (j + 3 <= n - 1 && s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0') {
                    indices.insert(j);
                }
            }
            if (i - 3 >= 0) {
                indices.erase(i - 3);

                j = i - 3;
                if (j + 3 <= n - 1 && s[j] == '1' && s[j + 1] == '1' && s[j + 2] == '0' && s[j + 3] == '0') {
                    indices.insert(j);
                }
            }

            if (indices.size() > 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}
