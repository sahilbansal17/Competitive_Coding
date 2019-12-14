#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;
    int t;
    cin >> t;

    int n;
    while (t--) {
        cin >> n;
        vector<int> v(n);
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            ++cnt[v[i]];
        }

        int steps = 0;
        for (auto it = cnt.rbegin(); it != cnt.rend(); ++it) {
            int num = it->first;
            int ct = it->second;
            // cout << num << " " << ct << endl;
            if (!(num & 1)) {
                cnt[num/2] += cnt[num];
                ++steps;
            }
        }
        cout << steps << endl;
    }

    return 0;
}