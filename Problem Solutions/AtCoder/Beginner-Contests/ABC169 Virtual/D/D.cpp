#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
// #define MULTIPLE_TESTS 1

ll n;

void solve() {
    cin >> n;
    int ans = 0;
    for (int i = 2; i <= sqrt(n); ++i) {
        int cnt = 0;
        while (n % i == 0) {
            n /= i;
            ++cnt;
        }
        int cur = (-1 + sqrt(1 + 8*cnt))/2;
        ans += cur;
    }
    if (n != 1) {
        ans += 1; // left over is prime
    }
    cout << ans << endl;
}

int main() {
    FAST_IO;
    int t = 1;
    #ifdef MULTIPLE_TESTS
    cin >> t;
    #endif

    while (t--) {
        solve();
    }

    return 0;
}