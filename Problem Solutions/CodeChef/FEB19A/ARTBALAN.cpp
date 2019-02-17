#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
	#endif

	int T, len, res, distinct, req, cur_res;

	cin >> T;

	string s;
	vector <int> cnt(26);
	while (T --) {
		cin >> s;

		len = s.length();

		// reset
		res = len;
		distinct = 0;
		for (int i = 0; i < 26; i ++) {
			cnt[i] = 0;
		}

		for (int i = 0; i < len; i ++) {
			if (cnt[s[i] - 'A'] == 0) {
				distinct ++;
			}
			cnt[s[i] - 'A'] ++;
		}

		sort (cnt.begin(), cnt.end(), greater <int> ());

		/*/
		for (int i = 0; i < distinct; i ++) {
			cout << cnt[i] << " ";
		}	
		//*/	

		for (int preserve = 1; preserve <= 26; preserve ++) {
			if (len % preserve == 0) {
				cur_res = 0;
				req = len/preserve;	
				for (int idx = 0; idx < preserve; idx ++) {
					if (cnt[idx] < req) {
						cur_res += req - cnt[idx];
					}
				}
				if (cur_res < res) {
					res = cur_res;
				}
				// cerr << cur_res << endl;
			}
		}
		cout << res << "\n";
	}
	return 0;
}