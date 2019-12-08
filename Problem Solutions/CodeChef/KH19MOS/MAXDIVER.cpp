/*
 * Gives Wrong Answer
 */
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const ll MAX = 100010LL;

int main() {

    FAST_IO;

    int t;
    cin >> t;

    int n, k;
    vector<int> a(MAX);
    unordered_map<int, int> cnt;
    vector<int> sorted;

    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++cnt[a[i]];
        }

        ll total = 1ll*n*(n - 1)/2;
        for (auto x: cnt) {
            int c = x.second;
            if (c == 1) {
                continue;
            }
            sorted.push_back(c);
        }
        sort(sorted.begin(), sorted.end(), greater<int>());
        for (int i = 0; i < sorted.size(); ++i) {
            int c = sorted[i];
            // cout << c << endl;
            if (k >= c - 1) {
                k -= (c - 1);
            } else {
                c -= k;
                k = 0;
                total -= 1ll*c*(c - 1)/2;
                cout << c*(c-1)/2 << endl;
            }
        }
        cout << total << endl;

        cnt.clear();
        sorted.clear();
    }
    return 0;
}