#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const ll MOD = 1e9 + 7;

void solve() {
    string s;
    string t;
    cin >> s;
    cin >> t;

    int n = s.length();
    priority_queue<ll, vector<ll>, greater<ll>> diff;

    ll cnt = 0;
    ll res = LLONG_MAX;
    ll prev = -1;
    ll cur;
    ll blocks = 0;
    bool occurred = false;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            ++cnt;
            if (prev != -1) {
                // cout << i - prev << endl;
                diff.push(i - prev);
                ++blocks;
                prev = -1;
            }
            occurred = true;
        } else if (prev == -1 && occurred) {
            prev = i;
        }
    }
    ++blocks;
    res = cnt*blocks;
    while (!diff.empty()) {
        // cout << diff.top() << endl;
        ll cur = diff.top();
        cnt += cur;
        --blocks;
        res = min(res, cnt*blocks);
        diff.pop();
    }
    cout << res << endl;
}

int main() {

    FAST_IO;    

    ll t;
    cin >> t;
    // t = 1;

    while (t --) {
        solve();
    }

    return 0;
}