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

    ll sum = 0;

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    
    ll pow = 1;
    for (int i = 0; i < 30; i ++) {
        ll count = 0;
        for (int j = 0; j < n; j ++) {
            if (a[j] & (1 << i)) {
                count ++;
            }
        }
        sum += ((count) * (count - 1))/2 * pow;
        pow *= 2;
    }

    cout << sum << endl;
    return 0;
}