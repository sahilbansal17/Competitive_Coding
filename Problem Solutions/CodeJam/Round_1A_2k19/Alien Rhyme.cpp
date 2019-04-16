// works for the small case

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

// bool fn(string s1, string s2) {
//     int n1 = s1.length();
//     int n2 = s2.length();
//     if (n1 == n2) {
//         return s1 < s2;
//     }
//     return n1 > n2;
// }

int main(){ 

    FAST_IO;

    int t, n;
    cin >> t;

    string s;
    int res;
    for (int i = 0; i < t; i ++) {
        res = 0;
        cin >> n;
        vector <string> w;
        map <string, int> done;
        vector <int> vis(n + 1, 0);
        for (int j = 0; j < n; j ++) {
            cin >> s;
            w.push_back(s);
        }
        
        // sort(w.begin(), w.end(), fn);
        // for (int j = 0; j < n; j ++) {
        //     cerr << w[j] << endl;
        // }

        vector < pair <int, string> > vp;
        for (int j = 0; j < n; j ++) {
            string maxsuff;
            for (int k = j + 1; k < n; k ++) {
                int n1 = w[j].length();
                int n2 = w[k].length();
                int i1 = n1 - 1;
                int i2 = n2 - 1;
                string suff;
                if (n1 > n2) {
                    while (i2 >= 0) {
                        if (w[j][i1] == w[k][i2]) {
                            suff += w[j][i1];
                        }
                        else {
                            break;
                        }
                        i2 --;
                        i1 --;
                    }
                }
                else {
                    while (i1 >= 0) {
                        if (w[k][i2] == w[j][i1]) {
                            suff += w[k][i2];
                        }
                        else {
                            break;
                        }
                        i2 --;
                        i1 --;
                    }
                }
                int t = suff.length();
                int p = maxsuff.length();
                if (t > p) {
                    maxsuff = suff;
                }
            }
            vp.push_back({maxsuff.length(), w[j]});
        }

        sort(vp.begin(), vp.end());
        reverse(vp.begin(), vp.end());
        
        for (int j = 0; j < n; j ++) {
            // cerr << vp[j].second << endl;
            w[j] = vp[j].second;
        }
        // for (int j = 0; j < n; j ++) {
        //     cerr << w[j] << endl;
        // }

        for (int j = 0; j < n; j ++) {
            if (vis[j] == 1) {
                continue;
            }
            string maxsuff;
            int match;
            for (int k = j + 1; k < n; k ++) {
                if (vis[k] == 1) {
                    continue;
                }
                int n1 = w[j].length();
                int n2 = w[k].length();
                int i1 = n1 - 1;
                int i2 = n2 - 1;
                string suff;
                if (n1 > n2) {
                    while (i2 >= 0) {
                        if (w[j][i1] == w[k][i2]) {
                            suff += w[j][i1];
                        }
                        else {
                            break;
                        }
                        i2 --;
                        i1 --;
                    }
                }
                else {
                    while (i1 >= 0) {
                        if (w[k][i2] == w[j][i1]) {
                            suff += w[k][i2];
                        }
                        else {
                            break;
                        }
                        i2 --;
                        i1 --;
                    }
                }
                int t = suff.length();
                int p = maxsuff.length();
                if (t > p) {
                    match = k;
                    maxsuff = suff;
                }
            }
            int t = maxsuff.length();
            while (t) {
                if (!done[maxsuff]) {
                    // cerr << maxsuff << endl;
                    done[maxsuff] = 1;
                    vis[j] = 1;
                    vis[match] = 1;
                    res += 2;
                    break;
                }
                maxsuff.pop_back();
                t --;
            }
        }
        cout << "Case #" << i + 1 << ": " << res << endl;
    }

    return 0;
}