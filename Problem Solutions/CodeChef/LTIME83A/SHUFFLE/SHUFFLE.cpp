#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MOD = 1e9 + 7;

#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> a(n);
    int i = 0;
    for (auto &x: a) {
        cin >> x.first;
        x.second = i;
        ++i;
    }
    sort(a.begin(), a.end());

    i = 0;
    bool pos = true;
    while (i < n) {
        int curpos = a[i].second;
        if (abs(curpos - i) % k != 0) {
            pos = false;
            break;
        }
        ++i;
    }
    if (pos) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
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