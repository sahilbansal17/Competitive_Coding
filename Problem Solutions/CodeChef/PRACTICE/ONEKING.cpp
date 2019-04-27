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

struct Interval {
    int start;
    int end;
    Interval(int s, int e) {
        start = s;
        end = e;
    }
};

bool sort_fn(Interval i1, Interval i2) {
    return i1.end < i2.end;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;    

    int t, n, a, b;
    cin >> t;

    for (int i = 0; i < t; i ++) {
        cin >> n;

        vector <Interval> v;
        for (int j = 0; j < n; j ++) {
            cin >> a >> b;
            v.push_back(Interval(a, b));
        }

        sort(v.begin(), v.end(), sort_fn);

        int k = 0, res = 0;
        while (k < n) {
            // cur_start: v[k].start
            // cur_end:   v[k].end
            bool done = 0;
            for (int j = k + 1; j < n; j ++) {
                // if j & k overlap, no need to consider j later
                if (max(v[k].start, v[j].start) <= min(v[k].end, v[j].end)) {
                    continue;
                }
                else {
                    k = j;
                    done = 1;
                    break;
                }
            }
            res ++;
            if (done == 0) {
                break;
            }
        }
        cout << res << endl;
    }

    return 0;
}