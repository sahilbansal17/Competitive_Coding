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

    int a, b;
    cin >> a >> b;

    int x, y;
    cin >> x >> y;

    
    int i = a;
    int j = x;
    bool res = 0;
    while (i != b && j != y) {
        if (i == j) {
            res = 1;
            break;
        }
        if (i == n) {
            i = 1;
        }
        else {
            i ++;
        }

        if (j == 1) {
            j = n;
        }
        else {
            j --;
        }
    }
    if (i == j) {
        res = 1;
    }

    if (res) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}
