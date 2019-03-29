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

vector <ll> a(MAX), pref_sum(MAX);
ll solve(ll n, ll p) {

	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}

	sort (a.begin(), a.begin() + n);

	for (int i = 0; i < n; i ++) {
		if (i - 1 >= 0) pref_sum[i] = a[i] + pref_sum[i - 1];
		else pref_sum[i] = a[i];
		// cerr << pref_sum[i] << " ";
	}
	// cerr << endl;

	ll res = 9223372036854775807;
	ll cur_res;
	for (int i = p - 1; i < n; i ++) {
		if (i - p >= 0)
			cur_res = p*a[i] - (pref_sum[i] - pref_sum[i - p]);
		else 
			cur_res = p*a[i] - pref_sum[i];
		// cerr << cur_res << " ";
		if (cur_res < res) {
			res = cur_res;
		}
	}
	// for (int i = 0; i < n; i ++) {
	// 	cerr << a[i] << " ";
	// }
	// cerr << endl;
	return res;
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

	int n, p;
	ll res;
	for (int i = 1; i <= t; ++i) {
			
		cin >> n >> p;

		res = solve(n, p);
		cout << "Case #" << i << ": " << res << endl;
	}

  return 0;
}
