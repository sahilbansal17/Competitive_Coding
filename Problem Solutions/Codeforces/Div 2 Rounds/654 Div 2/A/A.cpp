#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'
#define TESTCASES 1

void solve() {
    int n, m;
    cin >> n >> m;

    int x = ceil((1.0*n*m)/2);
    cout << x << endl;

}

int32_t main() {
    FAST_IO;

    int t;
    #ifdef TESTCASES
    cin >> t;
    #endif

    #ifndef TESTCASES
    t = 1;
    #endif

    while (t--) {
        solve();
    }
    
    return 0;
}