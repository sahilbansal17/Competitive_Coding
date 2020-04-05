#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7;

void solve(int case_no) {
    
    string s;
    cin >> s;

    int open = 0;
    int n = s.length();

    cout << "Case #" << case_no << ": ";
    for (int pos = 0; pos < n; ++pos) {
        int cur = (s[pos] - '0');
        while (open < cur) {
            cout << '(';
            ++open;
        }
        while (open > cur) {
            cout << ')';
            --open;
        }
        cout << cur;
    }
    while (open) {
        cout << ')';
        --open;
    }
    cout << endl;
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