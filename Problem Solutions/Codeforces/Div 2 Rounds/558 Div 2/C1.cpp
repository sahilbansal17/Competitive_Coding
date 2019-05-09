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

    int x, y;
    vector < pair <int, int> > points;
    for (int i = 0; i < n; i ++) {
        cin >> x >> y;
        points.push_back({x, y});
    }
    
    vector < pair <int, int> > m;
    vector < pair <int, int> > intercept;
    map < pair < pair <int, int>, pair <int, int> >, int> cnt;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            // connect a line between the two points
            int num = points[j].second - points[i].second;
            int den = points[j].first - points[i].first;
            int d = gcd(num, den);
            num /= d;
            den /= d;
            int i_num = den*points[i].second - num*points[i].first;
            int i_den = den;
            d = gcd(i_num, i_den);

            cnt[{{num, den}, {i_num, i_den}}] ++;
            if (cnt[{{num, den}, {i_num, i_den}}] == 1) {
                m.push_back({num, den});
                intercept.push_back({i_num, i_den});
            }
        }
    }

    // find intersection points between all the lines
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