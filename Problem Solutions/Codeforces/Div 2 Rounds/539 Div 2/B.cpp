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

    vector <int> a(n);

    int max_odd = 0, max_even = 0, mini = 101, sum = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        sum += a[i];
    }    

    sort (a.begin(), a.end());

    int cur_sum = sum, res = sum;
    for (int i = 2 ; i <= 100; i ++) {
        cur_sum = sum;
        for (int j = n - 1; j >= 0; j --) {
            if (a[j] % i == 0) {
                cur_sum -= (a[j] - a[j]/i);
                cur_sum += a[0]*(i - 1);
                break;
            }
        }
        if (cur_sum < res) {
            res = cur_sum;
        }
    }

    cout << res << endl;
    return 0;
}