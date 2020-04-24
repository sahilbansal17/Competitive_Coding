#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<pair<int, int>> pos;
        int x;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            pos.push_back({x, i});
        }
        sort(pos.begin(), pos.end());

        int last = n - 1;
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (pos[i].second == last) {
                --last;
            } else {
                int cur = pos[i].second;
                // cout << cur << endl;
                for (int j = cur; j <= last; ++j) {
                    if (i >= n) {
                        possible = false;
                        break;
                    }
                    if (pos[i].second != j) {
                        possible = false;
                        break;
                    }
                    ++i;
                }
                if (!possible) {
                    break;
                }
                // decrease by one, because increased one extra time!
                --i;
                last = cur - 1;
            }
        }
        if (possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    
    return 0;
}