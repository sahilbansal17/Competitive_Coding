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

    string s;
    cin >> s;

    int left = 0, right = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '(') {
            left ++;
        }
        else if (s[i] == ')') {
            right ++;
        }
    }

    int left_rem = n/2 - left;
    int right_rem = n/2 - right;
    if (left_rem < 0 || right_rem < 0) {
        cout << ":(" << endl;
        return 0;
    }

    int diff = 0;
    bool res = 1;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '?' && left_rem) {
            s[i] = '(';
            diff ++;
            left_rem --;
        }
        else if (s[i] == '?' && right_rem) {
            s[i] = ')';
            if (diff == 0) {
                res = 0;
                break;
            }
            diff --;
            right_rem --;
        }
        else if (s[i] == '(') {
            diff ++;
        }
        else if (s[i] == ')' && diff > 0) {
            diff --;
        }
        else {
            res = 0;
            break;
        }
        if (diff == 0 && i != n - 1) {
            res = 0;
            break;
        }
    }
    if (diff > 0) {
        res = 0;
    }

    if (res == 0) {
        cout << ":(" << endl;
    }
    else {
        cout << s << endl;
    }
    
    return 0;
}