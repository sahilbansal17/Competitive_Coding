#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;
    int t;
    cin >> t;

    vector<ll> v;
    for (int num = 1; num <= 9; ++num) {
        int cur = num;
        v.push_back(cur);
        // cout << cur << " ";
        for (int k = 0; k < 8; ++k) {
            cur = cur*10 + num;
            v.push_back(cur);
            // cout << cur << " ";
        }
        // cout << endl;
    }
    sort(v.begin(), v.end());
    
    int n;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        int res = 0;
        for (int j = 0; j < v.size(); ++j) {
            if (v[j] <= n) {
                ++res;
            } else {
                break;
            }
        }
        cout << res << endl;
    }

    return 0;
}