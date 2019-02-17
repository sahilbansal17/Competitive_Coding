#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 200010LL;

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

    int n, m, k;
    cin >> n >> m >> k;

    vector <ll> a(n), as(n);
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
        as[i] = a[i];
    }

    sort (as.begin(), as.end(), greater <int> ());

    ll res = 0;
    for (int i = 0; i < m*k; i ++) {
        // cerr << as[i] << endl;
        res += as[i];
    }

    cout << res << endl;

    map <int, int> cnt;
    for (int i = 0 ; i < m*k; i ++) {
        cnt[as[i]] ++;
    }

    int cur = 0, done = 0;
    for (int i = 0; i < n; i ++) {
        if (cnt[a[i]] > 0) {
            cnt[a[i]] --;
            cur ++;
        }
        if (cur == m && done < k - 1) {
            cout << i + 1 << " ";
            cur = 0;
            done ++;
        }
    }

    return 0;
}