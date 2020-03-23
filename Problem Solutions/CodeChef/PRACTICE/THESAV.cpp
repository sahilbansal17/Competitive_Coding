#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const ll MAX = 1000010;

int main() {
    FAST_IO;
    
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        int n = s.length();

        stack<char> unmatched;
        int cur = 0;
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                unmatched.push('*');
            } else if (s[i] == '0' && !unmatched.empty()) {
                ++cur;
                if (cur == 2) {
                    unmatched.pop();
                    cur = 0;
                }
            } else {
                possible = false;
                break;
            }
        }
        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}