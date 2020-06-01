#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    int co = 0, ce = 0;
    for (auto &a: arr) {
        cin >> a;
        if (a & 1) {
            ++co;
        } else {
            ++ce;
        }
    }
    if (ce == 0 && x % 2 == 0) {
        cout << "No" << endl;
    } else if (co % 2 == 1) {
        cout << "Yes" << endl;
    } else if (x == co + ce || co == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
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