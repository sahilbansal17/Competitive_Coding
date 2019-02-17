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

vector < pair <ll, ll> > facs;

void factorize(long long n) 
{ 
    ll count = 0; 
  
    // count the number of times 2 divides  
    while (!(n % 2)) { 
        n >>= 1; // equivalent to n=n/2; 
        count++; 
    } 
  
    // if 2 divides it 
    if (count) 
        facs.push_back(make_pair(2, count));
  
    // check for all the possible numbers that can  
    // divide it 
    for (long long i = 3; i <= sqrt(n); i += 2) { 
        count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count) 
            facs.push_back(make_pair(i, count));
    } 
  
    // if n at the end is a prime number. 
    if (n > 2) 
        facs.push_back(make_pair(n, 1));
} 

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    ll n, b;
    cin >> n >> b;

    factorize(b);

    ll a, cnt = 0, ca, cn;
    ll cur_res, ans = LLONG_MAX;

    for (int i = 0; i < facs.size(); i ++) {
        cur_res = 0;

        a = facs[i].first;
        cnt = facs[i].second;

        // cerr << a << " " << cnt << endl;
        ca = a;
        cn = n;
        while (cn/a > 0) {
            cur_res += cn/a;
            cn /= a;
        }

        cur_res = cur_res/cnt;

        if (cur_res < ans) {
            ans = cur_res;
        }
    }

    cout << ans << endl;

    return 0;
}