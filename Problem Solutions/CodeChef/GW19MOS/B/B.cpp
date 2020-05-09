#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (auto &x: a) {
        cin >> x;
        sum += x;
    }
    int q;
    cin >> q;
    int x;
    int res = sum/n;

    int id = 0;
    int cur = res;
    int prev = res;
    int cnt = 1;
    a.push_back(cur);
    while (cnt != n) {
        sum -= a[id];
        sum += cur;
        cur = sum/n;
        if (cur != prev) {
            cnt = 1;
        } else {
            ++cnt;
        }
        a.push_back(cur);
        prev = cur;
        // cout << cur << endl;
        ++id;
    }
    res = a.back();

    while (q--) {
        cin >> x;
        if (x <= a.size()) {
            cout << a[x - 1] << endl;
        } else {
            cout << res << endl;
        }
    }
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