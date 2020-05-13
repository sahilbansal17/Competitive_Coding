#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    string s, t;
    cin >> s >> t;

    for (char ch = 'a'; ch <= 'z'; ++ch) {
        if (s + ch == t) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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