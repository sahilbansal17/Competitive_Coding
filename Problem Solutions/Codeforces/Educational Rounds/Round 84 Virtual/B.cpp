#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'
void solve() {
    int n;
    cin >> n;

    int k;
    vector<int> res(n, -1);
    vector<int> done(n, 0);
    vector<int> married(n, 0);
    int ct = 0;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        vector<int> g(k);
        for (int j = 0; j < k; ++j) {
            cin >> g[j];
            g[j]--;
            if (!done[g[j]] && res[i] == -1) {
                res[i] = g[j];
                done[g[j]] = 1;
                ++ct;
                married[i] = 1;
            }
        }
    }
    if (ct == n) {
        cout << "OPTIMAL" << endl;
    } else {
        cout << "IMPROVE" << endl;
        int daughter = -1;
        for (int i = 0; i < n; ++i) {
            if (!married[i]) {
                daughter = i;
                break;
            }
        }
        int prince = -1;
        for (int i = 0; i < n; ++i) {
            if (!done[i]) {
                prince = i;
                break;
            }
        }
        cout << daughter + 1 << " " << prince + 1 << endl;
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