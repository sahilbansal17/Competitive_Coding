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

    while (t--) {
        cin >> n >> k;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            ++cnt[a[i]];
        }

        ll total = (1ll*n*(n - 1))/2;
        if (k >= n) {
            cout << total << endl;
            continue;
        }
        priority_queue<int> sorted;
        for (auto x: cnt) {
            int c = x.second;
            if (c == 1) {
                continue;
            }
            sorted.push(c);
        }
        while (k-- && !sorted.empty()) {
            int term = sorted.top();
            sorted.pop();
            if (term == 1) {
                break;
            }
            sorted.push(term - 1);
        }
        while (!sorted.empty()) {
            int c = sorted.top();
            total -= (1ll*c*(c - 1))/2;
            sorted.pop();
        }
        cout << total << endl;

    }
    return 0;
}