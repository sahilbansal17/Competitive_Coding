#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;
    
    int t;
    cin >> t;

    int n;
    while (t --) {
        cin >> n;
        string s;
        cin >> s;

        int i = 0;
        int res = 0;
        int cur = 0;
        while (i < n) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u') {
                if (i != 0 && s[i] != s[i - 1]) {
                    ++cur;
                } else {
                    if (cur > res) {
                        res = cur;
                    }
                    cur = 1;
                }
            } else {
                if (cur > res) {
                    res = cur;
                }
                cur = 0;
            }
            ++i;
        }
        if (cur > res) {
            res = cur;
        }
        cout << res << endl;
    }
    return 0;
}