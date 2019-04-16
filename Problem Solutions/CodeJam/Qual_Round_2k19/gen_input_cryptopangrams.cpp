// input generator for Cryptopangrams

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
    freopen("/Users/sahilbansal/Desktop/input.txt", "w", stdout);
    #endif

    FAST_IO;    

    int l = 25;

    int a[26] = {2,      3,      5,     7,     11,     13,     17,     19,     23,     29, 31,     37,     41,     43,     47,     53,     59,     61,     67,     71, 73,     79,     83,     89,     97,    101};
    
    for (int i = 0; i < l; i ++) {
        cout << a[i]*a[i + 1] << " ";
    }

    return 0;
}