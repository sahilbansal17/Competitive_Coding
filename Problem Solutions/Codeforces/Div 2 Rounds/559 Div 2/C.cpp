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

    int n, m;
    cin >> n >> m;

    vector <ll> b(n, 0), g(m, 0);
    ll max_b = -1, min_g = 100000001, sum_b = 0;
    for (int i = 0; i < n; i ++) {
        cin >> b[i];
        if (b[i] > max_b) {
            max_b = b[i];
        }
        sum_b += b[i];
    }

    for (int j = 0; j < m; j ++) {
        cin >> g[j];
        if (g[j] < min_g) {
            min_g = g[j];
        }
    }

    if (max_b > min_g) {
        cout << "-1" << endl;
        return 0;
    }

    if (n == 1 && m == 1 && b[0] != g[0]) {
        cout << "-1" << endl;
        return 0;
    }

    sort(b.begin(), b.end());
    sort(g.begin(), g.end());

    ll res;
    res = sum_b * m;

    int girl = m - 1;
    int boy = n - 1;
    int streak = 0;

    while (girl >= 0 && boy >= 0) {
        int diff = g[girl] - b[boy];
        // cerr << diff << endl;
        if (diff == 0) {
            break;
        }
        if (streak + 1 == m) {
            boy --;
            if (boy < 0) {
                // cerr << "here" << endl;
                res = -1;
                break;
            }
            streak = 0;
        }
        else {
            streak ++;
            res += diff;
            girl --;
        }
    }
    cout << res << endl; 
    return 0;
}