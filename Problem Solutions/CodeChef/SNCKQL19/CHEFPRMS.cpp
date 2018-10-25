#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n) {
	if (n == 1) {
		return 0;
	}
	if (n == 2 || n == 3) {
		return 1;
	}
	for (int i = 2; i <= sqrt(n); i ++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

vector <int> primes;
vector <int> is_semi_prime(201, 0);

int main() {

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
	#endif

	int t, n;
	cin >> t;

	for (int i = 2; i <= 200; i ++) {
		if (checkPrime(i)) {
			primes.push_back(i);
		}
	}

	for (int i = 0; i < primes.size() - 1; i ++) {
		int prime1 = primes[i];
		int j = i + 1;
		int prime2 = primes[j];
		while (prime1 * prime2 <= 200 && j < primes.size()) {
			is_semi_prime[prime1*prime2] = true;
			prime2 = primes[++j];
		}
	}

	/*/
	for (int i = 0; i < primes.size(); i ++) {
		if (is_semi_prime[i]) {
			cout << i << " ";
		}
	}
	cout << endl;
	//*/

	while (t --) {
		cin >> n;

		bool done = false;
		for (int i = 6; i <= 200; i ++) {
			if (is_semi_prime[i] && n >= i && is_semi_prime[n - i]) {
				// cerr << i << " " << n - i << endl;
				cout << "YES\n";
				done = true;
				break;
			}
		}

		if (!done) {
			cout << "NO\n";
		}
	}

}