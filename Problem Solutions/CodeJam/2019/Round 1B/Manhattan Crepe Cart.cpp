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

int main(){ 

    FAST_IO;

    int t, p, q;
    cin >> t;

    for (int i = 0; i < t; i ++) {
        cin >> p >> q;

        int x[p], y[p];
        char d[p];

        for (int j = 0; j < p; j ++) {
            cin >> x[j] >> y[j] >> d[j];
        }

        int res_x = -1, res_y = -1, count_max = -1;
        for (int l = 0; l <= q; l ++) {
            for (int r = 0; r <= q; r ++) {
                int count = 0;
                for (int z = 0; z < p; z ++) {
                    if (d[z] == 'N') {
                        if (r > y[z]) {
                            count ++;
                        }
                    }
                    else if (d[z] == 'S') {
                        if (r < y[z]) {
                            count ++;
                        }
                    }
                    else if (d[z] == 'E') {
                        if (l > x[z]) {
                            count ++;
                        }
                    }
                    else {
                        if (l < x[z]) {
                            count ++;
                        }
                    }
                }
                // cerr << l << " " << r << " " << count << endl;
                if (count > count_max) {
                    count_max = count;
                    res_x = l;
                    res_y = r;
                }
            }
        }
        cout << "Case #" << i + 1 << ": " << res_x << " " << res_y << endl;
    }

    return 0;
}