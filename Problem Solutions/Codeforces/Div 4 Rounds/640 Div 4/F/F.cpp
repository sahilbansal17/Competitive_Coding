#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    bool amark = false;
    if (a == 1) {
        cout << "00";
        amark = true;
    } else if (a > 1) {
        for (int i = 0; i <= a; ++i) {
            cout << 0;
        }
        amark = true;
    }
    bool mark = false;
    if (c == 1) {
        cout << "11";
        if (amark) {
            --b;
        }
        mark = true;
    } else if (c > 1) {
        for (int i = 0; i <= c; ++i) {
            cout << 1;
        }
        if (amark) {
            --b;
        }
        mark = true;
    }

    if (b == 1) {
        if (mark) {
            cout << 0;
        } else if (amark) {
            cout << 1;
        } else {
            cout << "01";
        }
    } else if (b > 1) {
        if (mark) {
            int x = 0;
            for (int i = 0; i < b; ++i) {
                cout << x;
                x ^= 1;
            }
        } else if (amark) {
            int x = 1;
            for (int i = 0; i < b; ++i) {
                cout << x;
                x ^= 1;
            }
        } else {
            int x = 0;
            for (int i = 0; i <= b; ++i) {
                cout << x;
                x ^= 1;
            }
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