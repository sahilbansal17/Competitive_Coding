#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

const ll MOD = 1e9 + 7;
int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;

        string s;
        cin >> s;

        int n = s.length();
        int cur = 0;
        // perform the operations until length becomes >= x
        while (s.length() < x) {
            string temp = s.substr(cur + 1);
            for (int i = 0; i < s[cur] - '0' - 1; ++i) {
                s += temp;
            }
            // cout << s << endl;
            ++cur;
        }
        
        ll len = 1ll*n; // final value of len after performing operation x times
        ll cnt = 1;
        for (int i = 0; i < x; ++i) {
            len = cnt + (((len - cnt + MOD) % MOD)*(s[i] - '0')) % MOD;
            len %= MOD;
            ++cnt;
        }
        cout << len << endl;
    }

    return 0;
}