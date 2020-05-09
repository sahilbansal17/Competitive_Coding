#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    string s;
    cin >> s;

    int sa, sb;
    cin >> sa >> sb;

    int n = s.length();
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            a = i + 1;
        } else if (s[i] == 'B') {
            b = i + 1;
        }
    }
    while (a <= b && a <= n && b >= 1) {
        if (a == b) {
            cout << "unsafe" << endl;
            return;
        }
        a += sa;
        b -= sb;
    }
    cout << "safe" << endl;
    return;
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