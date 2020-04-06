#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int d;
    cin >> d;

    vector<int> p(d);
    for (auto &x: p) {
        cin >> x;
    }

    queue<pair<int, int>> infected;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            infected.push({i, 0});
            ++res;
        }
    }

    int cur_day = 0;
    unordered_map<int, int> isolated;
    while (!infected.empty()) {

        auto front = infected.front();
        infected.pop();
        int day = front.second;
        // breaking condition
        if (day == d) {
            break;
        }
        // cur_day = day
        int isolate = p[day] - 1; // 0-based
        isolated[isolate] = 1;

        int cur = front.first;
        int left = front.first - 1;
        int right = front.first + 1;
        if (!isolated[cur] && left >= 0) {
            // can go left
            if (s[left] != '1') {
                s[left] = '1';
                ++res;
                infected.push({left, day + 1});
            }
        }
        if (right < n && !isolated[right]) {
            // can go right
            if (s[right] != '1') {
                s[right] = '1';
                infected.push({right, day + 1});
                ++res;
            }
        }
    }
    cout << res << endl;
}
int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}