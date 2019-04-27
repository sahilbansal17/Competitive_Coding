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

class EllysTicketPrices{
private:
	
	public:
		double getPrice(int n, vector <int> c, int t) {
			double low = 0, high = 100000000, mid;
			double targ = t*1.0;
			while (low < high) {
				mid = (low + high)/2;
				mid = round (mid * 100.0) / 100.0;
				double v = solve(n, mid, c);
				if (v > targ) {
					high = mid;
				}
				else if (v < targ) {
					low = mid + 0.005;
				}
				else {
					break;
				}
				// cout << low << " " << high << " " << mid << " " << v << endl;
			}
			return mid;
		}
		double solve(int k, double p, vector <int> c) {
			int n = k - 1;
			double res = p;
			double curr = p;
			for (int i = 0; i < n; i ++) {
				curr = curr * (100.0 + 1.0*c[i])/100.0;
				curr = round(curr * 100.0)/100.0;
				res += curr;
			}
			double final = (res/(n + 1));
			final = round(final * 100.0)/100.0;
			return final;
		}
		double round( double val ) {
		    if( val < 0 ) return ceil(val - 0.5);
		    return floor(val + 0.5);
		}
	
};

int main(){

	EllysTicketPrices a;
	
	
	int b[] = {30,-26,87,47,-39,25,-67,62,-38,68,-84,5,28,-20,50,-61,10,63,-71};
	vector <int> v(b, b + 19);
	cout << "\n" << a.getPrice(20, v, 392) << "\n";
}