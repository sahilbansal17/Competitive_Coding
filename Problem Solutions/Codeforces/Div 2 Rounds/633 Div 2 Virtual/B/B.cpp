#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }
    sort(arr.begin(), arr.end());
    vector<int> res;
    int i = 0, j = n - 1;
    while (i < j) {
        res.push_back(arr[j]);
        res.push_back(arr[i]);
        ++i;
        --j;
    }
    if (i == j) {
        res.push_back(arr[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        cout << res[i] << " ";
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