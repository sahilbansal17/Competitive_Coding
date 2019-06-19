#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 1010;

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

        vector <int> h(n, 0);
        vector <int> k(n, 0);

        int max_query = 0;
        for (int j = 0; j < n; j ++) {
            cin >> h[j];
            max_query = max(max_query, 2*h[j]);
        }

        for (int j = 0; j < n; j ++) {
            cin >> k[j];
        }

        // minimum steps to get a sum using the array 'k' elements
        int min_steps[MAX];
        memset(min_steps, 1000000, sizeof(min_steps));
        min_steps[0] = 0;

        for (int i = 1; i <= max_query; i ++) {
            // compute min_steps[i];
            for (int j = 0; j < n; j ++) {
                if (i >= k[j]) {
                    min_steps[i] = min(min_steps[i - k[j]] + 1, min_steps[i]);
                }
            }
            // cerr << min_steps[i] << " ";
        }

        ll res = 0;

        for (int j = 0; j < n; j ++) {
            res += min_steps[2*h[j]];
        }

        cout << res << endl;
    }

    return 0;
}