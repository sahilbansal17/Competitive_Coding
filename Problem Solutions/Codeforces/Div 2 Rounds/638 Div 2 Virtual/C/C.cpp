#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> cnt(26, 0);
    int uniq = 0;
    for (int i = 0; i < n; ++i) {
        ++cnt[s[i] - 'a'];
        if (cnt[s[i] - 'a'] == 1) {
            ++uniq;
        }
    }

    sort(s.begin(), s.end());
    int done = 0;

    char last = s[n - 1];
    if (s[0] == s[k - 1]) {
        cout << s[0];
        if (s[k] == s[n - 1]) {
            int tot = ceil((1.0*(n-k))/k);
            string res(tot, s[k]);
            cout << res << endl;
        } else {
            cout << s.substr(k) << endl;
        }
    } else {
        cout << s[k - 1] << endl;
    }
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