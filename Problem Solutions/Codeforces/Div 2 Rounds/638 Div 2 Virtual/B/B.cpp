#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    vector<int> done(n + 1, 0);
    set<int> nums;
    for (auto &a: arr) {
        cin >> a;
        if (!done[a]) {
            done[a] = 1;
            nums.insert(a);
        }
    }

    if (nums.size() > k) {
        cout << -1 << endl;
        return;
    }
    int cur = 1;
    while (nums.size() < k && cur <= n) {
        if (!done[cur]) {
            nums.insert(cur);
        }
        ++cur;
    }

    vector<int> req(nums.begin(), nums.end());
    cout << n*k << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cout << req[j] << " ";
        }
    }
    cout << endl;
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