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

    string s;
    cin >> s;

    string s1, s2;
    int n = s.length();
    bool res = 0;
    int count = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'a') {
            count ++;
            continue;
        }
        else {
            s1 += s[i];
        }
    }

    int n1 = s1.length();
    if (!(n1 & 1)) {
        bool temp = 1;
        // cerr << s1 << endl;
        for (int i = 0, j = n1/2; i < (n1/2) && j < n1; i ++, j ++) {
            if (s1[i] != s1[j]) {
                // cerr << i << " " << j << endl;
                temp = 0;
                break;
            }
        }
        if (temp == 1) {
            res = 1;
        }
        for (int i = 0; i < count + n1/2; i ++) {
            s2 += s[i];
        }
    }

    if (res == 0) {
        cout << ":(" << endl;
    }    
    else {
        int n2 = s2.length();
        string s3;
        for (int i = 0; i < n2; i ++) {
            if (s2[i] != 'a') {
                s3 += s2[i];
            }
        }
        if (s2 + s3 != s) {
            cout << ":(" << endl;
        }
        else {
            cout << s2 << endl;
        }
    }

    return 0;
}