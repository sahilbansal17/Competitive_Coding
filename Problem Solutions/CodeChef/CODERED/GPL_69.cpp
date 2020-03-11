#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

int main() {

    FAST_IO;
    
    ll m, n;
    cin >> m >> n;

    ll cnt[m][n][2];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i < n; i += 2) {
        cnt[0][i][0] = 1;
        cnt[0][i][1] = 0;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i - 1 >= 0 && j + 2 < n) {
                cnt[i][j][0] += cnt[i - 1][j + 2][1];
                cnt[i][j][1] += cnt[i - 1][j + 2][0];
            }
            if (i - 1 >= 0 && j - 2 >= 0) {
                cnt[i][j][0] += cnt[i - 1][j - 2][1];
                cnt[i][j][1] += cnt[i - 1][j - 2][0];
            }
            if (i - 2 >= 0 && j - 1 >= 0) {
                cnt[i][j][0] += cnt[i - 2][j - 1][1];
                cnt[i][j][1] += cnt[i - 2][j - 1][0];
            }
            if (i - 2 >= 0 && j + 1 < n) {
                cnt[i][j][0] += cnt[i - 2][j + 1][1];
                cnt[i][j][1] += cnt[i - 2][j + 1][0];
            }
            cnt[i][j][0] %= MOD;
            cnt[i][j][1] %= MOD;
        }
    }

    // for (int i = 0; i < m; ++i) {
    //     for (int j = 0; j < n; ++j) {
    //         cout << cnt[i][j][1] << " ";
    //     }
    //     cout << endl;
    // }

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += cnt[m - 1][i][1];
        res %= MOD;
        // cout << res << " ";
    }
    // cout << endl;
    cout << res << endl;
    return 0;
}