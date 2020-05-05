#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (auto &x: a) {
        cin >> x;
    }

    for (int i = 1; i < n; ++i) {
        int pos = d/i;
        int done = min(pos, a[i]);
        a[0] += done;
        d -= i*done;
    }
    cout << a[0] << endl;
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