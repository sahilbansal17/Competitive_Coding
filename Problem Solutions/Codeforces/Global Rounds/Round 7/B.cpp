#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

int main() {
    FAST_IO;
    
    int n;
    cin >> n;

    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    cout << b[0] << " ";
    ll maxi = b[0];
    for (int i = 1; i < n; ++i) {
        cout << maxi + b[i] << " ";
        maxi = max(maxi, maxi + b[i]);
    }
    cout << endl;
    return 0;
}