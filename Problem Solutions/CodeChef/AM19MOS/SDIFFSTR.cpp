#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        string s;
        int k;
        cin >> s >> k;
        int n = s.length();
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; ++i) {
            ++cnt[s[i] - 'a'];
        }
        int common = 0;
        string res;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] > 0) {
                if (common < k) {
                    res += ('a' + i);
                    ++common;
                }
            } else {
                res += ('a' + i);
            }
            if (res.length() == n) {
                break;
            }
        }
        if (res.length() != n) {
            cout << "NOPE" << endl;
        } else {
            cout << res << endl;
        }
    }

    return 0;
}