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

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        vector <int> idx, done(MAX, 0);

        for (int i = 0; i < n; i ++) {
            if (s[i] == s[0]) {
                idx.push_back(i);
            }
        }

        int cur = 1, max_count = idx.size(), cur_count = max_count;
        while (cur < n && cur_count == max_count) {
            cur_count = 0;
            for (int i = 0; i < max_count; i ++) {
                if (!done[idx[i]] && idx[i] + cur < n && s[idx[i] + cur] == s[cur]) {
                    cur_count ++;
                } 
                else {
                    done[idx[i]] = 1;
                }
            }
            cur ++;
            // cerr << cur_count << endl;
            if (cur_count < max_count) {
                cur --;
            }
        }
        for (int i = 0; i < cur; i ++) {
            cout << s[i];
        } 
        cout << endl;
    }

    return 0;
}