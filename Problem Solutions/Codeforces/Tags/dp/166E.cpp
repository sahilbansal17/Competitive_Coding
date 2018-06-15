#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define MOD 1000000007

int main(){

	ll n;
	cin >> n;

	/*
		This can be solved mathematical as follows:

		Let A(i) be the no. of ways to finish at vertex A after i moves 
		Similarly B(i), C(i) and D(i) are defined.

		A(i) = D(i-1) + B(i-1) + C(i-1)
		B(i) = D(i-1) + A(i-1) + C(i-1)
		C(i) = D(i-1) + A(i-1) + B(i-1)
		D(i) = A(i-1) + B(i-1) + C(i-1)

		The initial conditions are 
		A(0) = B(0) = C(0) = 0 and D(0) = 1

		Clubbing the A's, B's and C's to a single state:
		ABC(i) = D(i-1) + ABC(i-1) + ABC(i-1)
		i.e. ABC(i) = D(i-1) + 2*ABC(i-1)
		and 
		D(i) = ABC(i-1) + ABC(i-1) + ABC(i-1)

		So, D(i) = 3*ABC(i-1)

	*/

	ll prev_d = 1, prev_abc = 0, new_d, new_abc;

	for(int i = 1; i <= n ; i++){
		new_d = (3*prev_abc) % MOD;
		new_abc = (prev_d + 2*prev_abc) % MOD;
		prev_d = new_d;
		prev_abc = new_abc;
	}

	cout << new_d;
	return 0;
}