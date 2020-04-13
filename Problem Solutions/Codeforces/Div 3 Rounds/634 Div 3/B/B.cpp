#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    char ch = 'a';
    int i = 0;
    vector<char> res;
    while (i < a && i < n) {
        cout << ch;
        res.push_back(ch);
        --b;
        if (b > 0) {
            if (ch == 'z') {
                ch = 'a';
            } else {
                ++ch;
            }
        }
        ++i;
    }
    int cur = 0;
    int tot = res.size();
    while (i < n) {
        cout << res[cur];
        ++i;
        ++cur;
        if (cur == tot) {
            cur = 0;
        }
    }
    cout << endl;
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