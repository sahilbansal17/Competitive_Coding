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

    int n;
    cin >> n;

    vector <int> a(n + 1), odd(n + 1, 0), even(n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (i & 1) {
            odd[i] = odd[i - 1] + a[i]; 
            even[i] = even[i - 1];
        }
        else {
            odd[i] = odd[i - 1];
            even[i] = even[i - 1] + a[i];
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i ++) {
        int sum1 = odd[i - 1] + even[n] - even[i];
        int sum2 = even[i - 1] + odd[n] - odd[i];
        if (sum1 == sum2) {
            res ++;
        }
    }

    cout << res << endl;
    return 0;
}