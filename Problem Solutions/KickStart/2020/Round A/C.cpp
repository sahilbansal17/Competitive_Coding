#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MAX = 100010LL;
const ll MOD = 1e9 + 7;

bool possible(int diff, int k, vector<int>& m) {
    int prev = 0;
    int next = 1;
    int n = m.size();
    int cnt = 0;
    while (prev < n - 1) {
        int mp = m[prev];
        int mn = m[next];
        while (mp + diff < mn) {
            mp += diff;
            ++cnt;
        }
        ++prev;
        ++next;
    }
    if (cnt <= k) {
        return true;
    }
    return false;
}

void solve(int case_count) {

    int n, k;
    cin >> n >> k;

    vector<int> m(n);
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
    }

    int high = 0;
    for (int i = 0; i < n - 1; ++i) {
        int cur = m[i + 1] - m[i];
        if (cur > high) {
            high = cur;
        }
    }

    int low = 1;
    while (low < high) {
        int mid = low + ((high - low) >> 1);
        if (possible(mid, k, m)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << "Case #" << case_count << ": " << low << endl;
    return ;
}

int main () {
    FAST_IO;

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve(i);
    }

    return 0;
}