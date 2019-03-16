#include <iostream>
#include <map>
#include <vector>

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

vector <int> a(15);

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    int t, n;
    cin >> t;

    for (int i = 0; i < t; i ++) {
        cin >> n;
        for (int j = 0; j < n; j ++) {
            cin >> a[j];
        }

        ll res = 1;
        for (int k = 2; k <= 10000; k ++) {
            ll count = 0;
            for (int j = 0; j < n; j ++) {
                while (a[j] % k == 0) {
                    a[j] /= k;
                    count ++;
                }
            }
            res *= (count + 1);
        }
        for (int j = 0; j < n; j ++) {
            if (a[j] != 1) {
                res *= 2;
            }
        }
        cout << res << endl;
    }

    
    return 0;
}