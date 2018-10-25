#include <bits/stdc++.h>
using namespace std;

const int MAX = 100010;
int a[MAX], b[MAX];

int main() {

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
	#endif

	int t, n;
	cin >> t;

	while (t --) {
		cin >> n;

		for (int i = 0; i < n; i ++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i ++) {
			cin >> b[i];
		}

		int diff = 0;
		bool possible = true;
		for (int i = 0; i < n; i ++) {
			if (i >= n - 2 && a[i] != b[i]) {
				possible = false;
				break;
			}

			if (a[i] == b[i]) {
				continue;
			}

			if (a[i] < b[i]) {
				diff = b[i] - a[i];
				a[i] += diff;
				a[i + 1] += 2*diff;
				a[i + 2] += 3*diff;
			}
			else {
				possible = false;
				break;
			}
		}

		if (possible) {
			cout << "TAK" << endl;
		}
		else {
			cout << "NIE" << endl;
		}
	}

	return 0;
}