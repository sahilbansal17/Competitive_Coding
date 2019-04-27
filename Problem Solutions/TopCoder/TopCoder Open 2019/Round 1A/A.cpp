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

class EllysAndXor{
private:
	
	public:
		int getMax(vector <int> numbers) {
			int n = numbers.size();
			int max_res = 0;
			for (int i = 0; i < pow(2, n - 1); i ++) {
				int cur_res = numbers[0];
				for (int j = 0; j < n - 1; j ++) {
					if ((1 << j) & i) {
						cur_res = cur_res & numbers[j + 1];
					}
					else {
						cur_res = cur_res ^ numbers[j + 1];
					}
				}
				if (cur_res > max_res) {
					max_res = cur_res;
				}
			}
			return max_res;
		}
	
};

int main(){

	EllysAndXor a;
	
	vector <int> b(3);
	b[0] = 1;
	b[1] = 2;
	b[2] = 7;
	cout << "\n" << a.getMax(b) << "\n";
}