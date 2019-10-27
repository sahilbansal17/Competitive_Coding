/*
 * Problem Link: https://codeforces.com/contest/1250/problem/F
 */
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

int main() {
    FAST_IO;
    
    int n;
    cin >> n;

    int res = 4*n;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            res = min(res, 2*(i + n/i));
        }
    }
    cout << res << endl;
    return 0;
}