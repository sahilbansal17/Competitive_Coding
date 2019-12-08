#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

int main() {

    FAST_IO;

    int n, m;
    cin >> n >> m;

    vector<ll> ux, vy;
    int x, u, y, v;
    for (int i = 0; i < n; ++i) {
        cin >> x >> u;
        ux.push_back(1ll*u*x);
    }
    for (int i = 0; i < m; ++i) {
        cin >> y >> v;
        vy.push_back(1ll*v*y);
    }
    sort(ux.begin(), ux.end());
    sort(vy.begin(), vy.end());
    int i = 0, j = 0;
    int res = 0;
    while (i < n && j < m) {
        if (ux[i] < vy[j]) {
            ++i;
        } else if (vy[j] < ux[i]) {
            ++j;
        } else {
            ++res;
            ++i;
            ++j;
        }
    }
    cout << res << endl;
    return 0;
}