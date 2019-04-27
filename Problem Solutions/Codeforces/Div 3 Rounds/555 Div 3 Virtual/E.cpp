// Solution gets TLE

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

    int a[n], b[n], c[n];
    map <int, int> count;

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++) {
        cin >> b[i];
        count[b[i]] ++;
    }

    for (int i = 0; i < n; i ++) {
        int x = n - a[i];
        x %= n;
        while (count[x] == 0) {
            x ++;
            x %= n;
        }
        c[i] = (a[i] + x) % n;
        count[x] -- ;
    }

    for (int i = 0; i < n; i ++) {
        cout << c[i] << " ";
    }

    return 0;
}