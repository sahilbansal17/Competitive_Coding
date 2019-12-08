#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {

    FAST_IO;

    string s;
    cin >> s;

    int l = s.length();
    int res = 0;
    for (int i = 0; i < l/2; ++i) {
        if (i != l - i - 1 && s[i] != s[l - i - 1]) {
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}