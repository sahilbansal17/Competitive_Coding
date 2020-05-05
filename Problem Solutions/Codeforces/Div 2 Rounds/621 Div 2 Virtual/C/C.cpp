#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    vector<vector<ll>> suff(n, vector<ll> (26, 0));
    suff[n - 1][s[n - 1] - 'a'] = 1;
    for (int i = n - 2; i >= 0; --i) {
        int id = s[i] - 'a';
        for (int j = 0; j < 26; ++j) {
            if (j == id) {
                suff[i][j] = suff[i + 1][j] + 1;
            } else {
                suff[i][j] = suff[i + 1][j];
            }
        }
    }
    ll res = 0;
    // one letter hidden strings
    for (int i = 0; i < 26; ++i) {
        res = max(res, suff[0][i]);
    }

    // two letter hidden strings
    for (int first = 0; first < 26; ++first) {
        for (int second = 0; second < 26; ++second) {
            ll cur = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] - 'a' == first) {
                    cur += suff[i][second];
                }
                if (first == second) {
                    --cur;
                }
            }
            if (cur > res) {
                res = cur;
            }
        }
    }
    cout << res << endl;
}

int main() {
    FAST_IO;

    int t;
    // cin >> t;
    t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}