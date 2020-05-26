#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    string s;
    cin >> s;

    int l = 0, r = 0;
    int n = s.length();
    int c = 0;
    
    vector<int> cnt(4, 0);
    int res = n + 1;
    while (l < n) {
        while (l < n && c == 3) {
            res = min(res, r - l);
            --cnt[s[l] - '0'];
            if (cnt[s[l] - '0'] == 0) {
                --c;
            }
            ++l;
        }
        while (r < n && c < 3) {
            if (cnt[s[r] - '0'] == 0) {
                ++c;
            }
            ++cnt[s[r] - '0'];
            ++r;
        }
        if (c != 3 && res == n + 1) {
            cout << 0 << endl;
            return;
        }
        if (c == 3) {
            res = min(res, r - l);
        }
        --cnt[s[l] - '0'];
        if (cnt[s[l] - '0'] == 0) {
            --c;
        }
        ++l;
    }
    cout << res << endl;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}