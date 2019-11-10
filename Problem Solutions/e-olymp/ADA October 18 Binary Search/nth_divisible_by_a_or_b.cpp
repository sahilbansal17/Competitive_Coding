/*
 * Problem Link: https://www.e-olymp.com/en/contests/13949/problems/137353
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

ll gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
ll countLessThanMid(ll mid, ll a, ll b) {
    ll cnt = 0;
    cnt += mid/a;
    cnt += mid/b;

    ll lcm = a*(b/(gcd(a, b)));
    cnt -= mid/lcm;
    return cnt;
}
int main() {
    FAST_IO;
    
    ll a, b, n;
    cin >> a >> b >> n;

    // check for multiples of a
    ll low = 1, high = n;
    ll mid;

    ll res = -1;
    while (low <= high) {
        mid = low + ((high - low)>>1);
        ll cnt = countLessThanMid(a*mid, a, b);
        if (cnt == n) {
            res = a*mid;
            break;
        } else if (cnt > n) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (res != -1) {
        cout << res << endl;
        return 0;
    }

    low = 1;
    high = n;
    while (low <= high) {
        mid = low + ((high - low)>>1);
        int cnt = countLessThanMid(b*mid, a, b);
        if (cnt == n) {
            res = b*mid;
            break;
        } else if (cnt > n) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << res << endl;
    return 0;
}