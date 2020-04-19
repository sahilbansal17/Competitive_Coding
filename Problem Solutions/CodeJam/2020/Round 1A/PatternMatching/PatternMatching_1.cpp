/**
 * Passes Test Set 1 only
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7;
#define endl '\n'

void solve(int case_no) {

    int n;
    cin >> n;

    vector<string> right;
    int maxi = -1;
    string ansright = "";
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        
        right.push_back(s.substr(1));
        int p = s.length();
        if (p > maxi) {
            ansright = s.substr(1);
            maxi = s.length();
        }
    }

    int p = ansright.length();
    string res = ansright;
    bool poss = true;
    
    for (int i = 0; i < n; ++i) {
        string s = right[i];
        int m = s.length();
        for (int j = 0; j < min(m, p); ++j) {
            if (s[m - j - 1] != ansright[p - j - 1]) {
                poss = false;
                break;
            }
        }
        if (poss == false) {
            break;
        }
    }

    if (!poss) {
        res = "*";
    }
    cout << "Case #" << case_no << ": " << res << endl;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    for (int id = 1; id <= t; ++id) {
        solve(id);
    }
    
    return 0;
}