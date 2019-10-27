#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
int main() {
    FAST_IO;
    
    ll n;
    cin >> n;

    ll res = 1e13;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            res = min(res, (i - 1) + (n/i - 1));
        }
    }
    cout << res << endl;
    return 0;
}