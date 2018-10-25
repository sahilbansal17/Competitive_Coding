#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000010;
const long long MOD = 1000000007;
vector <long long> cnt(MAX, 0);

long long odd_product_till[MAX/10], even_product_till[MAX/10];

int main() {

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
	#endif

	int t, n;
	cin >> t;

	long long max_skill = 0, skill;
	long long res = 1;

	odd_product_till[1] = 1;
	for (long long i = 3; i < MAX/10; i += 2) {
		odd_product_till[i] = (odd_product_till[i - 2] * i) % MOD;
	}

	// cerr << even_product_till[2];
	// cerr << odd_product_till[3];

	while (t --) {
		cin >> n;

		max_skill = 0;
		res = 1;
		for (int i = 0; i < n; i ++) {
			cin >> skill;
			if (skill > max_skill) {
				max_skill = skill;
			}
			cnt[skill] ++;
		}

		long long c_cnt, current_skill = max_skill; // c_cnt : current_count
		bool backlog = false;

		while (current_skill > 0) {
			c_cnt = cnt[current_skill];

			if (backlog && c_cnt > 0) {
				res *= c_cnt;
				res %= MOD;
				c_cnt -= 1;
				backlog = false;
			}

			if (c_cnt == 0) {
				current_skill --;
				continue;
			}

			// cerr << current_skill << " " << c_cnt << endl;
			if (c_cnt & 1) {
				res *= c_cnt;
				res %= MOD;
				if (c_cnt >= 3) res *= odd_product_till[c_cnt - 2];
				backlog = true;
			}
			else {
				res *= odd_product_till[c_cnt - 1];
			}
			res %= MOD;
			current_skill --;
		}

		cout << res << endl;
		for (int i = 1; i <= max_skill; i ++) {
			cnt[i] = 0;
		}

		// cerr << endl;
	}

	return 0;
}