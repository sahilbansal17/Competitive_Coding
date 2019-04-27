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

int main() {

    FAST_IO;    

    int n, b, a;
    cin >> n >> b >> a;

    int s[n];
    for (int i = 0; i < n; i ++) {
        cin >> s[i];
    }    

    int max_a = a;
    int max_reached = n;
    for (int i = 0; i < n; i ++) {
        if (s[i] == 0) {
            if (a > 0) {
                a --;
            }
            else if (b > 0) {
                b --;
            }
            else {
                max_reached = i;
                break;
            }
        }
        else {
            if (a == max_a) {
                a --;
            }
            else if (b > 0) {
                b --;
                a ++;
            }
            else if (a > 0) {
                a --;
            }
            else {
                max_reached = i;
                break;
            }
        }
    }
    cout << max_reached << endl;
    return 0;
}