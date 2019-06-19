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

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    int t, n, x, y;
    cin >> t;

    for (int i = 0; i < t; i ++) {
        cin >> n;

        vector <ll> diff, sum;
        for (int j = 0; j < n; j ++) {
            cin >> x >> y; 
            diff.push_back(1ll*x - 1ll*y);
            sum.push_back(1ll*x + 1ll*y);
        }
        sort(diff.begin(), diff.end());
        sort(sum.begin(), sum.end());

        double res = -1, current_res;
        for (int j = 1; j < n; j ++) {
            current_res = abs((diff[j] - diff[j - 1])/2.0);
            current_res = min(current_res, abs((sum[j] - sum[j - 1])/2.0));
            if (res == -1) {
                res = current_res;
            }
            if (current_res < res) {
                res = current_res;
            }
        }
        cout << fixed;
        cout << setprecision(7) << res << endl;
    }
    return 0;
}