#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<ll> speed_a(n), speed_b(n);
    for (auto &a: speed_a) {
        cin >> a;
    }
    for (auto &b: speed_b) {
        cin >> b;
    }

    int max_a = *max_element(speed_a.begin(), speed_a.end());
    int max_b = *max_element(speed_b.begin(), speed_b.end());
    if (max_a != max_b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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