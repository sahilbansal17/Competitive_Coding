#include <iostream>
#include <map>
#include <vector>

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

    int t;
    cin >> t;

    string s;
    for (int i = 0; i < t; i ++) {
        cin >> s;

        int n = s.length(), p, q, cp, cq;
        if (n & 1) {
            p = n/2 - 1, q = n/2 + 1; 
        }
        else {
            p = n/2 - 1, q = n/2;
        }

        cp = p, cq = q; // copy
        bool inc = 0;
        while (p >= 0 && q < n) {
            if (inc) {
                s[q] = s[p];
            }
            else if (s[p] > s[q] && !inc) {
                s[q] = s[p];
                inc = 1;
            }
            else if (s[p] < s[q] && !inc) {
                bool done = false;
                if (n & 1) {
                    if (s[cp + 1] != '9') s[cp + 1] = s[cp + 1] + 1;
                    else s[cp + 1] = '0';
                }
                if (n & 1 && s[cp + 1] != '0') {
                    done = true;
                }
                while (cp >= 0 && cq < n) {
                    if (!done && s[cp] == '9') {
                        s[cp] = '0';
                        s[cq] = '0';
                    }
                    else if (!done) {
                        s[cp] = s[cp] + 1;
                        s[cq] = s[cp];
                        done = 1;
                    }
                    cp --; cq ++;
                }
                inc = 1;
                s[q] = s[p];
            }
            p --;
            q ++;
        }
        if (inc == 0) {
            bool done = false, nine = false;
            if (n & 1) {
                if (s[cp + 1] != '9') s[cp + 1] = s[cp + 1] + 1;
                else {
                    s[cp + 1] = '0';
                    nine = true;
                }
            }
            if (n & 1 && s[cp + 1] != '0') {
                done = true;
            }
            while (cp >= 0 && cq < n) {
                if (!done && s[cp] == '9') {
                    s[cp] = '0';
                    s[cq] = '0';
                }
                else if (!done) {
                    s[cp] = s[cp] + 1;
                    s[cq] = s[cp];
                    done = 1;
                }
                cp --; cq ++;
            }
            if (!done) {
                if (!nine && n == 1 && s[0] != '9') {
                    s[0] = s[0] + 1;
                    cout << s << endl;
                    continue;
                }
                cout << "1";
                for (int k = 0; k < n - 1; k ++) {
                    cout << "0";
                }
                cout << "1" << endl;
                continue;
            }
        }
        cout << s << endl;
    }

    return 0;
}