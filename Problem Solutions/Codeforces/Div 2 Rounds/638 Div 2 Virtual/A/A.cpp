#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;

    ll sum1 = 0;
    ll sum2 = 0;
    ll val = 2;
    for (int i = 1; i < n/2; ++i) {
        sum1 += val;
        val *= 2;
    }
    for (int i = n/2; i < n; ++i) {
        sum2 += val;
        val *= 2;
    }
    sum1 += val;
    cout << sum1 - sum2 << endl;
 
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