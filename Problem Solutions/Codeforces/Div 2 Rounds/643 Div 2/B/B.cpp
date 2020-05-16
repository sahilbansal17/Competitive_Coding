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

    sort(arr.begin(), arr.end());

    int i = 0;
    int res = 0;
    int cur = 0;
    while (i < n) {
        ++cur;
        if (cur == arr[i]) {
            ++res;
            cur = 0;
        }
        ++i;
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