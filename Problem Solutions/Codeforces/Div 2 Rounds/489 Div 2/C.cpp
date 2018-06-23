#include <bits/stdc++.h>

using namespace std;

/* Template file (modified) for Online Algorithmic Competitions */
/* Typedefs */
	/* Basic types */
	typedef long long ll;
	typedef unsigned long long ull;
/* Macros */
	/* Shorthand notations */
	#define MOD 1000000007

/*
 Function to calculate (x^y) % MOD
*/
ull modPower(ull x, ull y){
    ull res = 1;      
    x = x % MOD; 
    while (y > 0){
        if (y & 1){
            res = (res*x) % MOD;
        }
        y = y >> 1;
        x = (x * x) % MOD;  
    }
    return res;
}
	
int main(){

	ull x, k;

	cin >> x >> k;

	/*
	 The answer is simply (2^(k+1)*x - 2^k + 1)%MOD
	 But the tricky part is handling these modular addition and subtraction
	 When doing (a - b) % m we typically try doing (a % m - b % m) % m, which is what mathematics tells
	 but, the value inside the brackets might become negative, so this leads to wrong answer

	 To handle this, we need to do 
	 (a % m - b % m + m) % m

	 Also, since these values are large and to be stored in unsigned long long, 
	 the subtraction also yields wrong answers.

	 So, we need to convert these modular values to long long first (since m is typically 10^9 + 7 which fits in long long)
	 => we need to do (1ll * a % m - 1ll * b % m + m) % m

	 One more thing to note that, when we will be doing 
	 2^(k + 1)*x % MOD = (2^(k + 1) % MOD * x) % MOD
	 This will produce incorrect result since x is also very large and we need to take its modulo MOD first
	 i.e. 2^(k + 1)*x % MOD = (2^(k + 1) % MOD * (x % MOD)) % MOD 
	*/

	if(k == 0){
		/* Trivial case, k = 0 => output should be 2*x % MOD */
		cout << (2 * x) % MOD;		
	}
	else if(x == 0){
		/* Also, this is the corner case, when x = 0, output is simply 0 */
		cout << 0;
	}
	else{
		ull pow_2_k, pow_2_kPlus1, positive_term, negative_term;

		pow_2_k = (modPower(2, k) % MOD);

		pow_2_kPlus1 = (2 * pow_2_k) % MOD; // just to avoid multiple computations
		
		positive_term = ((pow_2_kPlus1 * (x % MOD)) % MOD + 1) % MOD;
		
		negative_term = pow_2_k;

		if(positive_term >= negative_term){
			cout << (1ll*positive_term - 1ll*negative_term);
		}
		else{
			cout << (1ll*positive_term - 1ll*negative_term + MOD)%MOD;
		}
		
	}

	return 0;
}