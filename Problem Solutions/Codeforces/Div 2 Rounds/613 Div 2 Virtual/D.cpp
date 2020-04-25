#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int n;
vector<int> a;

int solve(vector<int>& c, int bit) {
    if (bit < 0) {
        return 0;
    }
    vector<int> set, unset; // those with bit set or unset
    for (auto &x: c) {
        if ( ( 1 << bit) & x) {
            // set
            set.push_back(x);
        } else {
            unset.push_back(x);
        }
    }
    if (set.size() == 0) {
        return solve(unset, bit - 1);
    }
    if (unset.size() == 0) {
        return solve(set, bit - 1);
    }
    return min(solve(set, bit - 1), solve(unset, bit - 1)) + (1 << bit); // this bit will be 1 in the answer anyhow 
}

int main() {
    FAST_IO;

    cin >> n;
    a.resize(n);

    for (auto &x: a) {
        cin >> x;
    }

    cout << solve(a, 30) << endl;

    return 0;
}