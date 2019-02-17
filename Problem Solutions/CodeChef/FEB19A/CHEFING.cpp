#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
	#endif

	int T, n, len, res;

	cin >> T;

	string s;

	vector <int> cnt(26, 0), done(26, 0);
	while (T --) {
		cin >> n;

		// reset
		for (int i = 0; i < 26; i ++) {
			cnt[i] = 0;
		}
		res = 0;

		for (int i = 0; i < n; i ++) {
			// reset
			for (int i = 0; i < 26; i ++) {
				done[i] = 0;
			}
			// input
			cin >> s;
			len = s.length();
			// process
			for (int i = 0; i < len; i ++) {
				if (!done[s[i] - 'a']) {
					cnt[s[i] - 'a'] ++;
					done[s[i] - 'a'] = 1;
				}
			}
		}

		for (int i = 0; i < 26; i ++) {
			res += cnt[i]/n;
		}

		cout << res << endl;
	}
	return 0;
}