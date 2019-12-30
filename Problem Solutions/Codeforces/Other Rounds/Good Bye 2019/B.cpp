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
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool done = false;
        for (int i = 0; i < n - 1; ++i) {
            if (abs(a[i] - a[i + 1]) >= 2) {
                cout << "YES" << endl;
                cout << i + 1 << " " << i + 2 << endl;
                done = true;
                break;
            }
        }
        if (!done) {
            cout << "NO" << endl;
        }
    }

    return 0;
}