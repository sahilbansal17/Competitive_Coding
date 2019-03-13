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
        int n, k, l, r;
        cin >> n >> k;

        vector <int> a(MAX, 0);

        vector < pair<int, int> > seg;
        for (int i = 0; i < n; i ++) {
            cin >> l >> r;
            a[l] ++;
            a[r + 1] --;
            seg.push_back(make_pair(l, r));
        }

        vector <int> ct_k(MAX, 0), ct_k1(MAX, 0);
        for (int i = 1; i < MAX; i ++) {
            a[i] += a[i - 1];
            if (a[i] == k) {
                ct_k[i] = ct_k[i - 1] + 1;
            }
            else {
                ct_k[i] = ct_k[i - 1];
            }
            if (a[i] == k + 1) {
                ct_k1[i] = ct_k1[i - 1] + 1;
            }
            else {
                ct_k1[i] = ct_k1[i - 1];
            }
        }

        /*
        for (int i = 1; i <= 9; i ++) {
            cerr << ct_k1[i] << " ";
        }
        /*/

        int cres = 0, res = 0;
        for (int i = 0; i < n; i ++) {

            cres = 0;

            l = seg[i].first;
            r = seg[i].second;

            cres += ct_k[l - 1] + ct_k[MAX - 1] - ct_k[r];
            cres += ct_k1[r] - ct_k1[l - 1];
            
            // cerr << cres << endl;
            if (cres > res) {
                res = cres;
            }
        }
        cout << res << endl;
    }    

    return 0;
}