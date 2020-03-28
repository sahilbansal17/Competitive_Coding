#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

void solve() {
    int x, y;
    cin >> x >> y;

    unordered_map<int, int> ancestors;

    if (y > x) {
        swap(x, y);
    }
    int k = 0;
    while (y) {
        ancestors[y] = k;
        y /= 2;
        ++k;
    }
    int steps = 0;
    while (x) {
        if (ancestors.find(x) != ancestors.end()) {
            break;
        }
        x /= 2;
        ++steps;
    }
    steps += ancestors[x];
    cout << steps << endl;
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