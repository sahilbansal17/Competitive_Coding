/* 
 * Passes only subtask 1
 */


#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

bool isValid(vector<ll>& a, vector<ll>& b, int st, int en, ll x) {
    int cur = 0;
    int diff = abs(b[st] - a[0]);
    if (diff > x) {
        return 0;
    }
    for (int i = st; i <= en; ++i) {
        if (abs(b[i] - a[cur]) != diff) {
            return 0;
        }
        ++cur;
    }
    return 1;
}

void solve() {
    ll x;
    cin >> x;

    int n;
    cin >> n;
    vector<ll> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int m;
    cin >> m;
    vector<ll> B(m);
    for (int i = 0; i < m; ++i) {
        cin >> B[i];
    }

    ll res = 0;
    // m - n, ... m - 1 => (m - 1) - (m - n) + 1 = n
    for (int i = 0; i <= m - n; ++i) {
        int start = i;
        int end = i + n - 1;
        if (isValid(A, B, start, end, x)) {
            ++res;
        }
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