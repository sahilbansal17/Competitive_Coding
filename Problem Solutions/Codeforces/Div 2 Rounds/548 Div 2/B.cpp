#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 200010LL;

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

vector <int> a(MAX);

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    int n;
    cin >> n;

    ll a[MAX];
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    ll res = 0;

    ll cur, prev;
    cur = prev = a[n - 1];
    res += cur;
    for (int i = n - 2; i >= 0; i --) {
        cur = a[i];
        if (cur >= prev) {
            cur = prev - 1;
        }
        if (cur == 0) {
            break;
        }
        res += cur;
        prev = cur;
    }
    cout << res << endl;
    return 0;
}