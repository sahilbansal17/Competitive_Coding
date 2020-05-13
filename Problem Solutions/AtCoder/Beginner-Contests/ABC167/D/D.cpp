#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> arr(n);
    for (auto &a: arr) {
        cin >> a;
    }

    vector<int> next(n, -1);
    int cur = 0;
    vector<int> steps;
    while (next[cur] == -1) {
        next[cur] = arr[cur] - 1; // 0-based indexing
        cur = next[cur];
        steps.push_back(cur);
    }
    int cycle = cur; // start of cycle
    int len = 1; // length of cycle
    cur = next[cycle];
    while (cur != cycle) {
        cur = next[cur];
        ++len;
    }
    
    // already covered before cycle start
    int done = steps.size() - len;
    // remaining steps
    int rem = (k - done) % len;

    if (k <= steps.size()) { // if before cycle starts
        cout << 1 + steps[k - 1] << endl; // 1-based indexing
    } else { // simulate for remaining steps
        cur = cycle;
        while (rem) {
            cur = next[cur];
            --rem;
        }
        cout << 1 + cur << endl; // 1-based indexing
    }
}

int main() {
    FAST_IO;

    int t;
    // cin >> t;
    t = 1;

    while (t--) {
        solve();
    }
    
    return 0;
}