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

    vector <int> initial(n, 0);
    vector <pair <int, int> > a;
    int val;

    unordered_map <int, int> cnt1, cnt2;
    for (int i = 0; i < n; i ++) {
        cin >> val;
        initial[i] = val;
        cnt1[val] ++;
        if (cnt1[val] == 1) {
            a.push_back({val, i + 1});
        }
    }

    for (int i = 0; i < n; i ++) {
        int x = initial[i];
        cnt2[x]++;
        if (cnt2[x] != 1 && cnt2[x] == cnt1[x]) {
            a.push_back({x, i + 1});
        }
    }
    sort(a.begin(), a.end());

    // for (int i = 0; i < a.size(); i ++) {
    //     cerr << a[i].first << " " << a[i].second << endl;
    // }

    int k = a.size();
    int suffix_max[k], suffix_min[k];
    suffix_max[k - 1] = a[k - 1].second;
    suffix_min[k - 1] = a[k - 1].second;
    for (int j = k - 2; j >= 0; j --) {
        suffix_max[j] = max(suffix_max[j + 1], a[j].second);
        suffix_min[j] = min(suffix_min[j + 1], a[j].second);
    }   


    int res = INT_MAX, cur_res;
    for (int i = 0; i < a.size() - 1; i ++) {
        // cerr << min(a[i].first, a[i + 1].first) << " " << abs(a[i].second - a[i + 1].second) << endl;
        int j = a[i].second;
        int den = max(abs(j - suffix_max[i + 1]), abs(j - suffix_min[i + 1]));
        
        // cerr << a[i].first << " " << den << endl;
        cur_res = a[i].first/den;
        if (cur_res < res) {
            res = cur_res;
        }
    }

    cout << res << endl;
    return 0;
}