/**
 * Gives WA: need to figure out the mistake
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

vector<char> possible;
vector<int> cnt(26, 0);
bool countfungreater(char c1, char c2) {
    return cnt[c1-'A'] > cnt[c2-'A'];
}
void solve() {
    int U;
    cin >> U;

    int q;
    string r;
    
    set<char> digits;
    set<char> not_leading;
    for (int i = 0; i < 10000; ++i) {
        cin >> q >> r;
        
        int m = r.length();
        if (m != U) {
            continue;
        }
        ++cnt[r[0]-'A'];
        not_leading.insert(r[0]);
        for (char digit: r) {
            digits.insert(digit);
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (cnt[i] >= 1) {
            possible.push_back(i + 'A');
        }
    }

    sort(possible.begin(), possible.end(), countfungreater);
    for (char digit: digits) {
        if (not_leading.find(digit) == not_leading.end()) {
            cout << digit;
            break;
        }
    }
    for (int i = 0; i < 9; ++i) {
        cout << possible[i];
    }
    cout << endl;
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