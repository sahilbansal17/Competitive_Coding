#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    if (n <= 3) {
        cout << "-1" << endl;
        return;
    }
    int rem = n % 4;
    int sz = (rem == 0) ? n : n + 4 - rem;
    vector<int> res(sz);

    int k = sz - 3;
    int val = 1;
    while (k >= 1) {
        res[k] = val++;
        res[k + 2] = val++;
        res[k - 1] = val++;
        res[k + 1] = val++;
        k -= 4;
    }

    int start = 0, end = sz - 1;
    if (rem == 1) {
        start = 3;
        res[start] = n;
    } else if (rem == 2) {
        start = 2;
        res[start] = n;
        res[start + 1] = res[start + 2];
        res[start + 2] = n - 1;
    } else if (rem == 3) {
        start = 1;
        res[start] = n - 1;
        res[start + 1] = res[start + 3];
        res[start + 2] = n;
        res[start + 3] = n - 2;
    }

    for (int i = start; i <= end; ++i) {
        cout << res[i] << " ";
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