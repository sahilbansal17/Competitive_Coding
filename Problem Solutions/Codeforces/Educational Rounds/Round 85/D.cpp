#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

/*

N = 2
1 2
1

N = 3
1 2 1 3
2 3
1

N = 4
1 2 1 3 1 4
2 3 2 4
3 4
1

N = 5
1 2 1 3 1 4 1 5 => (5 - 1)*2 = 8 elements on this level
2 3 2 4 2 5 => (5 - 2)*2 = 6 elements on this level
3 4 3 5 => (5 - 3)*2
4 5 => (5 - 4)*2
1 => 1

*/

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;

    if (l == n*(n - 1) + 1) {
        cout << 1 << endl;
        return ;
    }

    ll level = 1;
    ll counted = 0;
    while (counted < l) {
        counted += (n - level) * 2;
        ++level;
    }
    --level;
    // now we know the level to look at
    counted -= (n - level)*2;
    ll shift = (l - counted);

    ll cur;
    if (shift & 1) {
        cur = level;
    } else {
        cur = level + (shift/2);
    }

    while (l <= r) {
        cout << cur << " ";
        ++shift;
        if (cur == n) {
            ++level;
            cur = level;
            shift = 1;
        } else if (cur == level) {
            cur = level + shift/2;
        } else {
            cur = level;
        }

        if (level == n) {
            cur = 1;
        }
        ++l;
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