#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;
#define endl '\n'

void solve() {
    ll n;
    cin >> n;

    ll pow = 2;
    ll cur = 3;
    while (1) {
        if (n % cur == 0) {
            cout << n/cur << endl;
            break;
        }
        pow *= 2;
        cur += pow;
    }
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