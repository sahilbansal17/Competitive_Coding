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

    int a[n];
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (a[i] == 1) {
            c1 ++;
        }
        else {
            c2 ++;
        }
    }

    if (c2 > 0) {
        cout << "2 ";
        c2 --;
    }

    if (c1 & 1) {
        for (int i = 0; i < c1; i ++) {
            cout << "1 ";
        }
        for (int i = 0; i < c2; i ++) {
            cout << "2 ";
        }
    }
    else if (c1 != 0) {
        cout << "1 ";
        c1 --;
        for (int i = 0; i < c2; i ++) {
            cout << "2 ";
        }
        for (int i = 0; i < c1; i ++) {
            cout << "1 ";
        }
    }
    else {
        for (int i = 0; i < c2; i ++) {
            cout << "2 ";
        }
    }
    cout << endl;

    return 0;
}