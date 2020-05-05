#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    string s;
    cin >> s;

    if (s[1] == 'B') {
        cout << "ARC" << endl;
    } else {
        cout << "ABC" << endl;
    }
 
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