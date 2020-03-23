#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
const ll MAX = 1000010;

int main() {
    FAST_IO;
    
    int n, m;
    cin >> n >> m;

    vector<ll> nums(n);
    for (auto &num: nums) {
        cin >> num;
    }
    sort(nums.begin(), nums.end(), greater<ll>());

    queue<ll> old, new_q;
    for (int i = 0; i < n; ++i) {
        old.push(nums[i]);
    }

    vector<ll> query(m);
    for (int i = 0; i < m; ++i) {
        cin >> query[i];
    }

    int cur_op = 0;
    ll maxi = query[m - 1];
    for (ll i = 0; i < maxi; ++i) {
        ll val1 = -1, val2 = -1;
        if (!old.empty()) {
            val1 = old.front();
        }
        if (!new_q.empty()) {
            val2 = new_q.front();
        }
        if (i == (query[cur_op] - 1)) {
            cout << max(val1, val2) << endl;
            ++cur_op;
        }

        if (val1 > val2) {
            old.pop();
            if (val1/2 != 0) {
                new_q.push(val1/2);
            }
        } else {
            new_q.pop();
            if (val2/2 != 0) {
                new_q.push(val2/2);
            }
        }
    }
    return 0;
}