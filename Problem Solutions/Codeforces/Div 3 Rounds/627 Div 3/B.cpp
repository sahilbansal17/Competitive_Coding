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

        vector<int> a(n);
        for (auto &x: a) {
            cin >> x;
        }

        vector<int> id(n + 1, -1);
        int elem;
        bool res = false;
        for (int i = 0; i < n; ++i) {
            elem = a[i];
            if (id[elem] != -1 && (i - id[elem]) != 1) {
                res = true;
                break;
            }
            if (id[elem] == -1) {
                id[elem] = i;
            }
        }
        if (res) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}