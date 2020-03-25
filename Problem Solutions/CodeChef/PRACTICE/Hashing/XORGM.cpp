#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main () {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        int total_xor = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            total_xor ^= a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
            ++cnt[b[i]];
            total_xor ^= b[i];
        }

        vector<int> res;
        int x;
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            x = a[i] ^ total_xor;
            if (cnt[x] > 0) {
                res.push_back(x);
                --cnt[x];
            } else {
                possible = false;
            }
        }
        if (!possible) {
            cout << "-1" << endl;
        } else {
            for (auto x: res) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}