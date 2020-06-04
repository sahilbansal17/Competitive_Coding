#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
// #define MULTIPLE_TESTS 1

int n;
vector<ll> arr;
void readArray() {
    arr.resize(n);
    for (auto &a: arr) {
        cin >> a;
    }
}

void solve() {
    cin >> n;
    readArray();
    ll res = arr[0];
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 0) {
            cout << 0 << endl;
            return;
        }
    }
    const ll MAX = 1e18;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > int64_t(MAX/res) ) {
            cout << "-1" << endl;
            return;
        }
        res *= arr[i];
    }
    cout << res << endl;
}

int main() {
    FAST_IO;
    int t = 1;
    #ifdef MULTIPLE_TESTS
    cin >> t;
    #endif

    while (t--) {
        solve();
    }

    return 0;
}