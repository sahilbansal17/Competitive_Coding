/*
 * Problem Link: https://www.e-olymp.com/en/contests/13949/problems/137350
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;
    
    int n, x;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> x;

    reverse(a.begin(), a.end());
    int idx = lower_bound(a.begin(), a.end(), x) - a.begin();
    cout << n - idx + 1 << endl;
    return 0;
}