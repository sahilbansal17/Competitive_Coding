#include <iostream>
#include <vector>

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

    for (int i = 0; i < t; i ++) {
        int n;
        ll x;
        cin >> n;

        vector <ll> a;
        for (int j = 0; j < n; j ++) {
            cin >> x;
            a.push_back(x);
        }

        ll res = 0;

        vector <ll> max_sum_till(n, 0), min_sum_till(n, 0);
        max_sum_till[0] = a[0];
        min_sum_till[0] = a[0];
        for (int j = 1; j < n; j ++) {
            max_sum_till[j] = max(a[j], max_sum_till[j - 1] + a[j]);
            min_sum_till[j] = min(a[j], min_sum_till[j - 1] + a[j]);
        }

        vector <ll> max_sum_from(n, 0), min_sum_from(n, 0);
        max_sum_from[n - 1] = a[n - 1];
        min_sum_from[n - 1] = a[n - 1];
        for (int j = n - 2; j >= 0; j --) {
            max_sum_from[j] = max(a[j], a[j] + max_sum_from[j + 1]);
            min_sum_from[j] = min(a[j], a[j] + min_sum_from[j + 1]);
        }

        vector <ll> min_min_sum_from(n, 0), max_max_sum_from(n, 0);
        min_min_sum_from[n - 1] = a[n - 1];
        max_max_sum_from[n - 1] = a[n - 1];
        for (int j = n - 2; j >= 0; j --) {
            max_max_sum_from[j] = max(max_max_sum_from[j + 1], max_sum_from[j]);
            min_min_sum_from[j] = min(min_min_sum_from[j + 1], min_sum_from[j]);
        }

        ll phase_1_sum = 0, phase_2_sum = 0;
        for (int j = 0; j < n - 1; j ++) {
            phase_1_sum = max_sum_till[j];
            phase_2_sum = min_min_sum_from[j + 1];
            res = max(res, abs(phase_1_sum - phase_2_sum));

            phase_1_sum = min_sum_till[j];
            phase_2_sum = max_max_sum_from[j + 1];
            res = max(res, abs(phase_2_sum - phase_1_sum));
        }

        cout << res << endl;
    }

    return 0;
}