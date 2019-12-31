/*
 * Help taken from the editorial:
 * https://codeforces.com/blog/entry/72330
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

bool possible(int res, int diff) {
    ll sum = (res * 1LL * (res + 1))/2;
    if (sum < diff) return false; // one of the no. will always be greater otherwise
    if ((sum & 1) == (diff & 1)) {
        // n*(n + 1)/2 and abs(a - b) must have the same parity
        // then only we can make them equal
        // because a + x = b + y, where x + y = n(n + 1)/2
        // consider all the cases and you will realize
        return true;
    }
    return false;
}

int main() {
    FAST_IO;

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        int diff = abs(a - b);
        if (diff == 0) {
            cout << "0" << endl;
            continue;
        }

        int res = 1;
        while (!possible(res, diff)) {
            ++res;
        }
        cout << res << endl;
    }
    return 0;
}