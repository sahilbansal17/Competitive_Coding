#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 300010LL;

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

    int a, b;
    vector <pair <int, int> > vp;
    cin >> a >> b;
    vector <int> poss;
    poss.push_back(a);
    poss.push_back(b);

    vp.push_back({a, b});
    for (int i = 1; i < m; i ++) {
        cin >> a >> b;
        vp.push_back({a, b});
    }

    vector <int> res;
    for (int j = 0; j < 2; j ++) {
        int cur = poss[j];
        int total = 0;
        int cnt[MAX] = {0};
        for (int i = 0; i < m; i ++) {
            if (vp[i].first != cur && vp[i].second != cur) {
                total ++;
                cnt[vp[i].first] ++;
                cnt[vp[i].second] ++;
            }
            else {
                continue;
            }
        }
        for (int i = 1; i <= n; i ++) {
            if (i == cur) {
                continue;
            }
            if (cnt[i] == total) {
                res.push_back(cur);
                res.push_back(i);
                // cerr << cur << " " << i << endl;
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;


    return 0;
}
