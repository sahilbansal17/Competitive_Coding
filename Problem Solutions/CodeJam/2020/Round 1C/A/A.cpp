#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int x, y;
    string s;
    cin >> x >> y;
    cin >> s;

    int l = s.length();
    int res = 1e9;
    for (int i = 0; i < l; ++i) {
        if (abs(x) + abs(y) <= i) {
            res = i;
            break; 
        }
        if (s[i] == 'S') {
            --y;
        } else if (s[i] == 'N') {
            ++y;
        } else if (s[i] == 'E') {
            ++x;
        } else {
            --x;
        }
    }
    if (res == 1e9 && abs(x) + abs(y) <= l) {
        res = l;
    }
    if (res == 1e9) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << res << endl;
    }
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    
    return 0;
}