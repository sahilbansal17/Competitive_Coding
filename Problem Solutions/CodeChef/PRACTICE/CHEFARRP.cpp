#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        int prod = 1;
        for (int j = i; j < n; ++j) {
            if (sum + a[j] > 1e9) {
                break;
            } else if (sum + a[j] == prod * a[j]) {
                ++res;
            }
            sum += a[j];
            prod *= a[j];
        }
    }
    cout << res << endl;
}

int main () {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}