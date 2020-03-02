#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    ll mini = 10000;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < mini) {
            mini = a[i];
        }
    }

    ll equal = -1;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        if (b[i] == 0) {
            equal = a[i];
        }
    }

    // SPECIAL CASE
    if (equal != -1) {
        // zero exists
        for (int i = 0; i < n; ++i) {
            if (b[i] == 0 && a[i] != equal) {
                cout << "-1" << endl;
                return 0;
            }
            if (b[i] != 0 && (a[i] < equal || ((a[i] - equal) % b[i]) != 0)) {
                cout << "-1" << endl;
                return 0;
            }
        }
        // possible
        int steps = 0;
        for (int i = 0; i < n; ++i) {
            if (b[i] == 0) {
                continue;
            }
            steps += ((a[i] - equal)/b[i]);
        }
        cout << steps << endl;
        return 0;
    }
    
    ll num = -1;
    for (ll i = mini; i >= 0; --i) {
        bool possible = true;
        for (int j = 0; j < n; ++j) {
            if (((a[j] - i) % b[j]) != 0) {
                possible = false;
                break;
            }
        }
        if (possible) {
            num = i;
            break;
        }
    }
    if (num == -1) {
        cout << "-1" << endl;
    } else {
        ll steps = 0;
        for (int j = 0; j < n; ++j) {
            steps += ((a[j] - num)/b[j]);
        }
        cout << steps << endl;
    }

    return 0;
}