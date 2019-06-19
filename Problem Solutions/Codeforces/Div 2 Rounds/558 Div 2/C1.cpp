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

    int n; // number of points
    cin >> n;

    int x, y;
    vector < pair <int, int> > points; // pair of (x, y)
    for (int i = 0; i < n; i ++) {
        cin >> x >> y;
        points.push_back({x, y});
    }
    
    vector < pair <int, int> > m; // slope pairs(numerator, denominator)
    /*
    vector < pair <int, int> > intercept; // intercept pairs(numerator, denominator)
    */
    map < pair < pair <int, int>, pair <int, int> >, int> cnt; // count of lines with given slope and intercept
    
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            // find slope numerator and denominator in max reducible form
            int num = points[j].second - points[i].second;
            int den = points[j].first - points[i].first;
            int d = gcd(num, den);
            
            if (d != 0) {
                // otherwise, can lead to division by zero
                num /= d;
                den /= d;
            }

            // find intercept numerator and denominators
            int i_num = den*points[i].second - num*points[i].first;
            int i_den = den;
            d = gcd(i_num, i_den);
            // need not divide intercept by d
            // that works because denominator will be same when slopes are same
            // so numerator has to also be same for getting the same intercept
            
            // increment the count of lines with given slope and intercept
            cnt[{{num, den}, {i_num, i_den}}] ++;
            if (cnt[{{num, den}, {i_num, i_den}}] == 1) {
                m.push_back({num, den});
                /*
                intercept.push_back({i_num, i_den});
                */
            }
        }
    }

    // count the no. of lines that intersect with each other
    int res = 0;
    for (int i = 0; i < m.size(); i ++) {
        for (int j = i + 1; j < m.size(); j ++) {
            if (m[j] != m[i]) {
                res ++;
            }
        }
    }
    cout << res << endl;
    
    return 0;
}