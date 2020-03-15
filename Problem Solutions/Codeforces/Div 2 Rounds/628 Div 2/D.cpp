#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;

int main() {

    FAST_IO;
    ll u, v;
    cin >> u >> v;

    if (((u & 1) != (v & 1)) || (u > v)) {
        cout << "-1" << endl;
        return 0;
    }

    if (u == 0 && v == 0) {
        cout << 0 << endl;
        return 0;
    }

    if (u == v) {
        cout << 1 << endl << u << endl;
        return 0;
    }

    ll x = (v - u)/2;
    if (u & x) {
        cout << 3 << endl << u << " " << x << " " << x << endl;
        return 0;
    }

    cout << 2 << endl << u + x << " " << x << endl;
    return 0;
}