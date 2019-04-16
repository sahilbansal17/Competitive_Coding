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

    FAST_IO;    

    int t;
    cin >> t;
    
    string s, res1, res2;
    int len;
    bool first_four;
    for (int i = 0; i < t; i ++) {
        cin >> s;
        len = s.length();
        first_four = false;
        for (int j = 0; j < len; j ++) {
            if (s[j] != '4') {
                res1 += s[j];
                if (first_four) {
                    res2 += '0';
                }
            }
            else {
                first_four = true;
                res1 += '3';
                res2 += '1';
            }
        }
        cout << "Case #" << i + 1 << ": " << res1 << " " << res2 << endl;
        res1.clear();
        res2.clear();
    }
    
    return 0;
}