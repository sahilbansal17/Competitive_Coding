#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(2*n);
        for (int i = 0; i < 2*n; ++i) {
            cin >> a[i];
        }

        int cnt[3] = {0};
        unordered_map<int, int> diff; // longest suffix with the given diff value
        diff[0] = 2*n; // in worst case, remove all in the right part
        for (int i = 2*n - 1; i >= n; --i) {
            ++cnt[a[i]];
            diff[cnt[1] - cnt[2]] = i;
        }

        // consider the prefix
        int res = 2*n; // in the worst case, empty all jars
        cnt[1] = 0;
        cnt[2] = 0;
        int left = n;
        int right = abs(n - diff[0]);
        res = min(res, left + right); // remove all in the left part
        for (int i = 0; i < n; ++i) {
            ++cnt[a[i]];
            --left;
            if (diff.count(cnt[2] - cnt[1]) > 0) {
                right = abs(n - diff[cnt[2] - cnt[1]]);
                res = min(res, left + right);
            }
        }
        cout << res << endl;
    }
    return 0;
}