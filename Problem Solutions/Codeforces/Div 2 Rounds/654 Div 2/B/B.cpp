#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'
#define TESTCASES 1

int n;
vector<ll> arr;
void readArray() {
    arr.resize(n);
    for (auto &a: arr) {
        cin >> a;
    }
}

void solve() {
    
    cin >> n;
    readArray();

    sort(arr.begin(), arr.end());
    int cur = n;
    for (int i = n - 1; i >= 0; --i) {
        if (arr[i] <= cur) {
            break;
        } else {
            --cur;
        }
    }
    cout << cur + 1 << endl;
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