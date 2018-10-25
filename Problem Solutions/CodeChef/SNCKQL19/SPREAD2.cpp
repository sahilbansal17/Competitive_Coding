#include <bits/stdc++.h>
using namespace std;

const int MAX = 100010;
long long a[MAX];
long long prefix_sum[MAX];

int main() {

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
	#endif

	int t, n;
	cin >> t;

	prefix_sum[0] = 0;
	while (t --) {
		cin >> n;

		long long current_person = 1, no_of_person_knowing = 1, no_of_days = 0;

		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			prefix_sum[i + 1] = prefix_sum[i] + a[i];
		}

		if (n == 1) {
			cout << "1" << endl;
			continue;
		}

		while (no_of_person_knowing < n) {
			no_of_person_knowing += prefix_sum[current_person];
			current_person += prefix_sum[current_person];
			// cerr << current_person << " " << no_of_person_knowing << endl;
			no_of_days ++;
		}

		cout << no_of_days << endl;
	}	

	return 0;
}