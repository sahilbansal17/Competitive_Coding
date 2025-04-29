#include <bits/stdc++.h>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long ll;

const ll MOD = 1000000007LL;
const ll MAX = 200010LL;

template <typename T> T gcd(T a, T b) {
    if(b == 0) {
        return a;
    }
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

int main() {

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
    freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
    #endif

    FAST_IO;

    ll t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<ll> a(n);
        ll total = 0;
        for (int j = 0; j < n; ++j) {
        	cin >> a[j];
        	total += a[j];
        }

    	vector <ll> preMax(n, 0);
    	preMax[0] = a[0];

    	for (int j = 1; j < n; ++j) {
    		preMax[j] = max(a[j], preMax[j - 1]);
    	}

    	cout << preMax[n - 1] << " ";

    	ll cur = 0;
    	for (int j = n - 1; j >= 1; --j) {
    		cur += a[j];
    		cout << cur + preMax[j - 1] << " ";
    	}
    	cout << endl;

    }

    return 0;
}
