#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;
    while (t--) {
        int n, s, k;
        cin >> n >> s >> k;

        unordered_map<int, int> closed;
        int x;
        for (int i = 0; i < k; ++i) {
            cin >> x;
            closed[x] = 1;
        }

        int cur = s, cur2 = s - 1;
        int dist1 = 0;
        while (cur <= n && closed.find(cur) != closed.end()) {
            ++dist1;
            ++cur;
        }
        if (cur == n + 1) {
            dist1 = INT_MAX;
        }

        int dist2 = 1;
        while (cur2 >= 1 && closed.find(cur2) != closed.end()) {
            ++dist2;
            --cur2;
        }
        if (cur2 == 0) {
            dist2 = INT_MAX;
        }

        cout << min(dist1, dist2) << endl;
    }

    return 0;
}