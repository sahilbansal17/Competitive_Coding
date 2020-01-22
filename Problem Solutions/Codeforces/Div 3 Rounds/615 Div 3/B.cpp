#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

bool mycmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main() {
    FAST_IO;

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;

        int x, y;
        vector<pair<int, int>> pts;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            pts.push_back({x, y});
        }
        sort(pts.begin(), pts.end(), mycmp);

        // for (auto yy: pts) {
        //     cout << yy.first << " " << yy.second << endl;
        // }
        int cx = 0, cy = 0;
        string res;
        bool poss = true;
        for (int i = 0; i < n; ++i) {
            x = pts[i].first;
            y = pts[i].second;
            if (cx <= x && cy <= y) {
                for (int j = cx; j < x; ++j) {
                    res += 'R';
                }
                for (int j = cy; j < y; ++j) {
                    res += 'U';
                }
                cx = x;
                cy = y;
            } else {
                poss = false;
                break;
            }
        }
        if (!poss) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << res << endl;
        }
    }

    return 0;
}