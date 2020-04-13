#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<int> filled(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> filled[i];
    }

    int cur_gap = 0;
    bool start = false;
    for (int i = 0; i < n; ++i) {
        if (filled[i] == 1 && !start) {
            start = true;
        } else if (start) {
            if (filled[i] == 0) {
                ++cur_gap;
            } else {
                ++cur_gap;
                if (cur_gap < 6) {
                    cout << "NO" << endl;
                    return ;
                }
                cur_gap = 0;
            }
        }
    }
    cout << "YES" << endl;
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