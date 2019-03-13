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

    int n, a, b;
    cin >> n;

    int res = 0, cura, curb, preva, prevb, highest = -1;

    cin >> cura >> curb;
    preva = cura;
    prevb = curb;

    int start, end;
    start = 0;
    end = min (cura, curb);

    if (end >= highest && end >= start) {
        res += end - max(highest, start) + 1;
        highest = end + 1;
    }
    else {
        res = 1;
        highest = 0;
    }

    for (int i = 0; i < n - 1; i ++) {
        cin >> a >> b;
        cura = a;
        curb = b;

        start = max (preva, prevb);
        end = min (cura, curb);

        // cerr << end << " " << start << " " << highest << endl;
        if (end >= highest && end >= start) {
            res += end - max(start, highest) + 1;
            highest = end + 1;
        }

        preva = a;
        prevb = b;
        // cerr << res << " " << highest << endl;
    }

    cout << res << endl;
    return 0;
}