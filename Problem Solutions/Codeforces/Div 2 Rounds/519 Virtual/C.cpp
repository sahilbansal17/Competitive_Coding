#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
// #define MULTIPLE_TESTS 1

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> res(n, 0);
    for (int i = 1; i < n; ++i) {
        if (s[i] == 'a') {
            res[i - 1] ^= 1;
            res[i] = 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    FAST_IO;
    int t = 1;
    #ifdef MULTIPLE_TESTS
    cin >> t;
    #endif

    while (t--) {
        solve();
    }

    return 0;
}