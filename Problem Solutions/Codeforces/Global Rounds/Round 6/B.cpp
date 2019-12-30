#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;
    
    int n;
    cin >> n;

    ll x;
    for (int i = 0; i < n; ++i) {
        cin >> x;

        bool done = false;
        for (int k = 1; k <= 6; ++k) {
            if ((x - 7 + k) % 14 == 0 && (x + k - 7) != 0) {
                cout << "YES" << endl;
                done = true;
                break;
            }
        }
        if (!done) {
            cout << "NO" << endl;
        }
    }

    return 0;
}