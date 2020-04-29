#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    string s;
    cin >> s;

    int n = s.length();
    if (n == 1 || n == 2) {
        cout << "YES" << endl;
        return;
    }
    bool res = 1;
    if (s[0] != s[n - 2]) {
        res = 0;
    }
    if (s[1] != s[n - 1]) {
        res = 0;
    }

    for (int i = 0; i < n - 2; ++i) {
        if (s[i] != s[i + 2]) {
            res = 0;
            break;
        }
    }

    if (res) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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