#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    int res = 0;
    for (auto &x: a) {
        cin >> x;
        res += x;
    }
    for (auto &x: b) {
        cin >> x;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0;
    int j = n - 1;

    while (k > 0 && i < n && j >= 0) {
        if (a[i] < b[j]) {
            res -= a[i];
            res += b[j];
            --k;
        } 
        ++i;
        --j;
    }
    cout << res << endl;
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