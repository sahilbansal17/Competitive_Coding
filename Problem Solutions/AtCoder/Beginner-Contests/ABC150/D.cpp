/*
 * Gives wrong answer
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
 
typedef long long ll;
 
ll gcd (ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
 
int main() {
 
    FAST_IO;
 
    // int n = 1e9;
    // int b = n/3;
    // int x = ceil((1.0*b)/2);
    // cout << x << endl;
 
    int n, m;
    cin >> n >> m;
 
    vector<ll> a(n);
 
    ll lcm = 1;
    ll d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            d = a[i]/2;
            lcm = a[i]/2;
        } else {
            d = gcd(lcm, a[i]/2);
            if (a[i]/2 * lcm > m*d) {
                cout << "0" << endl;
                return 0;
            }
            lcm = ((a[i]/2) * lcm)/d;
        }
    }
 
    // cout << lcm << endl;
    ll multiples = m/lcm;
    ll odd_multiples = ceil((1.0 * multiples)/2);
    cout << odd_multiples << endl;
    return 0;
}