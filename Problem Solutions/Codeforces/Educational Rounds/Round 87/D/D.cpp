#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

int count_less_equal_x(vector<int>& arr, vector<int>& k, int x) {
    int cnt = 0;
    for (auto a: arr) {
        if (a <= x) {
            ++cnt;
        }
    }

    for (auto y: k) {
        if (y > 0 && y <= x) {
            ++cnt;
        }
        if (y < 0 && abs(y) <= cnt) {
            --cnt;
        }
    }
    return cnt;
}
void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }
    vector<int> k(q);
    for (auto &x: k) {
        cin >> x;
    }

    // no element left at the end
    if (count_less_equal_x(arr, k, 1e6 + 1) == 0) {
        cout << 0 << endl;
        return;
    }

    int low = 0;
    int high = 1e6 + 1;
    while (high - low > 1) {
        int mid = (low + high)/2;
        if (count_less_equal_x(arr, k, mid) > 0) {
            high = mid;
        } else {
            low = mid;
        }
    }
    cout << high << endl;
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