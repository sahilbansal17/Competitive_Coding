// https://practice.geeksforgeeks.org/problems/decode-the-pattern/0

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

    int t, n;
    cin >> t;

    map <int, string> res;
    res[1] = "1";

    for (int i = 2; i <= 20; i ++) {
        int cnt = 1;
        string s = res[i - 1], s_new;
        int len = s.length();
        int s_idx = 0;
        while (s_idx < len - 1) {
            if (s[s_idx] != s[s_idx + 1]) {
                s_new += (cnt + 48);
                s_new += s[s_idx];
                cnt = 1;
            }
            else {
                cnt ++;
            }
            s_idx ++;
        }
        // consider last character
        s_new += (cnt + 48);
        s_new += s[s_idx];
        res[i] = s_new;
    }

    while (t --) {
        cin >> n;

        if (res.find(n) != res.end()) {
            cout << res[n] << endl;
        }
    }

    return 0;
}