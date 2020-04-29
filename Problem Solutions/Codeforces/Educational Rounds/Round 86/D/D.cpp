#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

vector<vector<int>> compute_for_me(vector<int>& m, vector<int> &c) {
    int n = m.size();
    int k = c.size();

    vector<int> cnt(k + 1, 0);
    for (int i = 0; i < n; ++i) {
        ++cnt[m[i]];
    }

    vector<vector<int>> res;
    // compute count of arrays with size >= i

    int ans = (int)ceil((1.0*cnt[k])/c[k - 1]);
    for (int i = k - 1; i >= 1; --i) {
        cnt[i] = cnt[i] + cnt[i + 1];
        ans = max(ans, (int)ceil((1.0*cnt[i])/c[i - 1]));
    }
    
    // cout << ans << endl;

    //*/
    res.resize(ans);
    sort(m.begin(), m.end());
    for (int i = 0; i < n; ++i) {
        int id = (i % ans);
        res[id].push_back(m[i]);
    }
    //*/
    return res;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> org(n);
    for (auto &sz: org) {
        cin >> sz;
    }

    vector<int> mxg(k);
    for (auto &req: mxg) {
        cin >> req;
    }

    vector<vector<int>> testcases = compute_for_me(org, mxg);

    cout << testcases.size() << endl;
    for (auto testcase: testcases) {
        cout << testcase.size() << " ";
        for (auto sz: testcase) {
            cout << sz << " ";
        }
        cout << endl;
    }
}

int main() {
    FAST_IO;

    int t;
    // cin >> t;
    t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}