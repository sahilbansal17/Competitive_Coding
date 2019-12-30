#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        ll x;
        ll sum = 0, xxor = 0;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            xxor ^= a[i];
        }
        cout << "2" << endl;
        cout << xxor << " " << sum + xxor << endl;
        sum = sum + xxor + (sum + xxor);
        xxor = sum + xxor;
    }    

    return 0;
}