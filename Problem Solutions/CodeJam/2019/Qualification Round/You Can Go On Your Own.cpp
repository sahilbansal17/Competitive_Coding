#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 500010LL;

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

    FAST_IO;    

    int t;
    cin >> t;

    string s, res;
    int n;
    
    for (int i = 0; i < t; i ++) {
        cin >> n;
        cin >> s;
        
        for (int j = 0; j < 2*n - 2; j ++) {
            if (s[j] == 'S') {
                res += 'E';
            }
            else {
                res += 'S';
            }
        }
        cout << "Case #" << i + 1 << ": " << res << endl;
        res.clear();
        
    }
    
    return 0;
}