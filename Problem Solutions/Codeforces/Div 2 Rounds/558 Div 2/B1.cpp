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

    unordered_map <int, int> cnt;
    int c, res = 0;
    for (int i = 0; i < n; i ++) {
        cin >> c;
        cnt[c] ++;

        int cnt1 = 0, cnt2 = 0;
        set <int> distinct;
        for (int j = 1; j <= 10; j ++) {
            if (cnt[j] > 0) {
                distinct.insert(cnt[j]);
            }
        }
        if (distinct.size() == 2) {
            vector <int> vals;
            for (auto val: distinct) {
                vals.push_back(val);
            }
            sort(vals.begin(), vals.end());
            int v1 = vals[0];
            int v2 = vals[1];
            for (int j = 1; j <= 10; j ++) {
                if (cnt[j] == v1) {
                    cnt1 ++;
                }
                else if (cnt[j] == v2) {
                    cnt2 ++;
                }
            }
            if ((cnt1 == 1 && v1 == v2 + 1) || (cnt2 == 1 && v2 == v1 + 1)) {
                res = i + 1;    
            }
            else if (cnt1 == 1 && v1 == 1) {
                res = i + 1;
            }
            else if (cnt2 == 1 && v2 == 1) {
                res = i + 1;
            }
        }
        else if (distinct.size() == 1) {
            vector <int> vals;
            for (auto val: distinct) {
                vals.push_back(val);
            }
            if (vals[0] == 1)
                res = i + 1;
            
            int cnt_one = 0, cnt_other = 0;
            for (int j = 1; j <= 10; j ++) {
                if (cnt[j] == vals[0]) {
                    cnt_one ++;
                }
                else if (cnt[j] > 0) {
                    cnt_other ++;
                }
            }
            if (cnt_one == 1 && cnt_other == 0) {
                res = i + 1;
            }
        }
    }
    cout << res << endl;
    
    return 0;
}