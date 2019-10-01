#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template <typename T> T gcd(T a, T b) { 
    if(b == 0) 
        return a; 
    return gcd(b, a % b); 
}

template <typename T> T power(T x, T y, ll m = MOD) {
    T ans = 1; 
    x %= m; 
    while (y > 0) { 
        if (y & 1LL) {
            ans = (ans * x) % m;   
        } 
        y >>= 1LL; 
        x = (x * x) % m; 
    } 
    return (ans % m); 
}

void solve(int case_no, int n, int k) {

    int c[n], d[n];

    for (int j = 0; j < n; j ++) {
        cin >> c[j];
    }
    for (int j = 0; j < n; j ++) {
        cin >> d[j];
    }

    int res = 0;
    for (int l = 0; l < n; l ++) {
        for (int j = l; j < n; j ++) {
            int max1 = -1, max2 = -1;
            for (int t = l; t <= j; t ++) {
                if (c[t] > max1) {
                    max1 = c[t];
                }
                if (d[t] > max2) {
                    max2 = d[t];
                }
            }
            if (abs(max1 - max2) <= k) {
                res ++;
                // cerr << k << " " << j << " " << max1 << " " << max2 << endl;
            }
        }
    }

    cout << "Case #" << case_no << ": " << res << endl;
}

int main(){ 

    FAST_IO;

    int t;
    cin >> t;

    int n, k;
    for (int i = 0; i < t; i ++) {
        cin >> n >> k;

        solve(i + 1, n, k);
    }

    return 0;
}