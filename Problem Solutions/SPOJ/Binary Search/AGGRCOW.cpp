/*
 * Problem Link: https://www.spoj.com/problems/AGGRCOW
 */
#include <bits/stdc++.h>
using namespace std;

bool possible(int mid, int c, vector<int>& x) {
    int cur_diff = 0;
    int used = 1;
    int n = x.size();
    for (int i = 1; i < n; ++i) {
        cur_diff += x[i] - x[i - 1];
        if (cur_diff >= mid) {
            ++used;
            cur_diff = 0;
        }
    }
    if (used >= c) {
        return true;
    }
    return false;
}

int solve(int n, int c, vector<int>& x) {
    sort(x.begin(), x.end());
    int low, high, cur;
    low = x[1] - x[0];
    high = x[n - 1] - x[0];
    for (int i = 1; i < n - 1; ++i) {
        cur = x[i + 1] - x[i];
        low = min(low, cur);
    }
    int mid;
    int ans;
    while (low <= high) {
        mid = low + ((high - low)/2);
        if (possible(mid, c, x)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main () {

    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;
        vector<int> x(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        cout << solve(n, c, x) << endl;
    }
    return 0;
}