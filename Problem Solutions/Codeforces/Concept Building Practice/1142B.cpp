/**
 * This problem can be used to illustrate the concept of two pointers approach 
 * in solving algorithmic problems.
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

#define int ll
void solve() {
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
 
    int i = 0, j = 0;
    int latest_at_b = -1;
    while (i < n && j < m && k > 0) {
        while (j < m && b[j] < a[i] + ta) {
            ++j;
        }
        if (j == m) {
            break;
        }
        --k; // cancel this flight at b[j]
        ++i;
        ++j;
    }
    while (i < n && j < m && b[j] < a[i] + ta) {
        ++j;
    }
    if (j == m || i == n) {
        latest_at_b = -1;
    } else {
        latest_at_b = b[j] + tb;
    }
    cout << latest_at_b << endl;
}

int32_t main() {
    FAST_IO;

    int t;
    // cin >> t; 
    t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}