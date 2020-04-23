#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'
const int MAX = 2e5 + 10;

void solve() {
    string s;
    cin >> s;

    int res = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            continue; // will be considered
        }
        int zeroes = 0;
        for (int j = i - 1; j >= 0; --j) {
            if (s[j] == '0') {
                ++zeroes; // will help in increasing the f value
            } else {
                break;
            }
        }
        int val = 0; // formed till the current j value from the i-th index
        for (int j = i; j < n; ++j) {
            val = (val * 2) + (s[j] - '0');
            if ((j - i + 1 + zeroes) >= val) {
                // if the value can be formed
                ++res;
            }
            if (val > n) {
                // can't be formed 
                break;
            }
        }
    }
    cout << res << endl;
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