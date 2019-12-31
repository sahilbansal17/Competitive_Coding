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

        int l, r;
        int max_right = -1;
        vector<pair<pair<int, int>, int> > seg;
        for (int i = 0; i < n; ++i) {
            cin >> l >> r;
            seg.push_back({{l, r}, i});
        }
        sort(seg.begin(), seg.end());
        
        vector<int> col(n, 0);
        int cur = 0;
        col[seg[0].second] = 0;
        max_right = seg[0].first.second;
        for (int i = 1; i < n; ++i) {
            if (seg[i].first.second <= max_right) {
                col[seg[i].second] = cur ^ 1;
            } else {
                cur = cur ^ 1;
                col[seg[i].second] = cur;
                max_right = seg[i].first.second;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << col[i];
        }
        cout << endl;
    }

    return 0;
}