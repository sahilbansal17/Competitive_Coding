/*
 * Problem Link: https://www.e-olymp.com/en/contests/13949/problems/137352
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;
    
    int n, q;
    cin >> n >> q;

    unordered_map<int, int> count;
    int val;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        ++count[val];
    }

    for (int i = 0; i < q; ++i) {
        cin >> val;
        if (count.find(val) != count.end()) {
            cout << count[val] << endl;
        } else {
            cout << "0" << endl;
        }
    }
    return 0;
}