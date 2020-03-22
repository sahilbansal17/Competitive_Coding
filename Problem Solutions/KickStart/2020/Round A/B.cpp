#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MAX = 100010LL;
const ll MOD = 1e9 + 7;

ll maxsum[51][1510];

ll rec_solve(int cur, int p, int k, vector<vector<ll> >& cost) {
    if (cur == cost.size()) {
        if (p == 0) {
            return 0;
        }
        return INT_MIN;
    }
    if (p == 0) {
        return 0;
    }
    if (maxsum[cur][p] != -1) {
        return maxsum[cur][p];
    }
    ll res = 0;
    for (int choose = 0; choose <= min(p, k); ++choose) {
        if (choose == 0) {
            res = max(res, rec_solve(cur + 1, p - choose, k, cost));
        } else {
            res = max(res, cost[cur][choose - 1] + rec_solve(cur + 1, p - choose, k, cost));
        }
    }
    return maxsum[cur][p] = res;
}

void solve(int case_count) {

    int n, k, p;
    cin >> n >> k >> p;

    vector<vector<ll> > cost(n, vector<ll>(k));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> cost[i][j];
            if (j != 0) {
                cost[i][j] += cost[i][j - 1];
            }
        }
    }

    ll res = rec_solve(0, p, k, cost);
    
    cout << "Case #" << case_count << ": " << res << endl;
    return ;
}

int main () {
    FAST_IO;

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        memset(maxsum, -1, sizeof(maxsum));
        solve(i);
    }

    return 0;
}