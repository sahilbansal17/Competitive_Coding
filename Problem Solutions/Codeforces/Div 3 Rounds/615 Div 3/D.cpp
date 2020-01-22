#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int q, x;
    cin >> q >> x;

    vector<int> next(x + 1);
    unordered_map<int, int> done;
    for (int i = 0; i < x; ++i) {
        next[i] = i;
    }
    int y;
    int cur = 0;

    while (q--) {
        cin >> y;

        int rem = y % x;
        int val = next[rem];
        done[val] = 1;
        
        val += x;
        while (done.find(val) != done.end()) {
            val += x;
        }
        next[rem] = val;

        while (done.find(cur) != done.end()) {
            ++cur;
        }
        cout << cur << endl;
    }

    return 0;
}