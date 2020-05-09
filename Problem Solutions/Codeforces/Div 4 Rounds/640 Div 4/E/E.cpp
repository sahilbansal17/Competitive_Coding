#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    vector<int> cnt(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int sum = arr[i];
        for (int j = i + 1; j < n; ++j) {
            sum += arr[j];
            if (sum <= n) {
                cnt[sum] = 1;
            } else {
                break;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[arr[i]] == 1) {
            ++res;
        }
    }
    cout << res << endl;
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