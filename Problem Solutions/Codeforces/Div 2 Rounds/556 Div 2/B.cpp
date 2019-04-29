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

    char c[n][n];
    for (int i = 0; i < n ; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> c[i][j];
        }
    }

    bool done[n][n];

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            done[i][j] = 0;
        }
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            bool res = 1;
            if (c[i][j] == '.' && done[i][j] == 0) {
                // cerr << i << " " << j << endl;
                for (int k = 0; k < 4; k ++) {
                    int i_new = i + dx[k];
                    int j_new = j + dy[k];
                    if (i_new < 0 || i_new >= n) {
                        res = 0;
                    }
                    if (j_new < 0 || j_new >= n) {
                        res = 0;
                    }
                    if (!done[i_new][j_new] && c[i_new][j_new] == '.') {
                        continue;
                    }
                    else {
                        res = 0;
                    }
                }
            }
            else {
                res = 0;
            }
            if (res == 1) {
                // cerr << i << " " << j << endl;
                done[i][j] = 1;
                for (int k = 0; k < 4; k ++) {
                    int i_new = i + dx[k];
                    int j_new = j + dy[k];
                    done[i_new][j_new] = 1;
                }
            }
        }
    }

    bool final = 1;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (c[i][j] == '.' && !done[i][j]) {
                final = 0;
                break;
            }
        }
    }

    if (final == 0) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
    return 0;
}