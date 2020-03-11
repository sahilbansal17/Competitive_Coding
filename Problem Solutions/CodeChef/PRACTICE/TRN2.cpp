#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

int main() {

    FAST_IO;
    
    ll t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> dist(n), waiting(n);
        for (int i = 0; i < n - 1; ++i) {
            cin >> dist[i];
        }
        for (int i = 1; i < n - 1; ++i) {
            cin >> waiting[i];
        }

        int q;
        cin >> q;
        int type, l, r;
        int a, b;
        while (q--) {
            cin >> type >> l >> r;
            a = min(l, r);
            b = max(l, r);
            int res = 0;
            --a;
            --b;
            for (int i = a; i < b; ++i) {
                res += dist[i];
            }
            int min_wait = INT_MAX;
            bool checked = false;
            for (int i = a + 1; i < b; ++i) {
                if (type == 0) {
                    res += waiting[i];
                } else {
                    checked = true;
                    min_wait = min(min_wait, waiting[i]);
                }
            }
            if (type == 1 && checked) {
                res += min_wait*(b - a - 1);
            }
            cout << res << endl;
        }
    }

    return 0;
}