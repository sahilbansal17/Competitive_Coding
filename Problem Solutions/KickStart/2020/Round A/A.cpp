#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll MAX = 100010LL;
const ll MOD = 1e9 + 7;

void solve(int case_count) {
    
    int n;
    ll b;
    cin >> n >> b;

    vector<ll> cost(n);
    for (auto &c: cost) {
        cin >> c;
    }

    sort(cost.begin(), cost.end());
    int cnt = 0;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
        if (sum + cost[i] <= b) {
            sum += cost[i];
            ++cnt;
        } else {
            break;
        }
    }
    cout << "Case #" << case_count << ": " << cnt << endl;
    return ;
}

int main () {
    FAST_IO;

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        solve(i);
    }

    return 0;
}