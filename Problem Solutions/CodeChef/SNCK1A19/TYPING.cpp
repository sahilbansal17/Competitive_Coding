#include <bits/stdc++.h>
using namespace std;

int main () {

	#ifndef ONLINE_JUDGE 
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
	#endif

	int t;
	cin >> t;
	
	while (t --) {

		int n;
		cin >> n;

		map <string, int> cnt;
		string s;

		int time = 0;

		for (int i = 0; i < n; i ++) {
			cin >> s;
			cnt[s] ++;

			int len = s.length(), cur_time = 2;
			bool prev_left = 0, cur_left = 0;

			if (s[0] == 'd' || s[0] == 'f') {
				prev_left = 1;
			}
			
			for (int j = 1; j < len; j ++) {

				if (s[j] == 'd' || s[j] == 'f') {
					cur_left = 1;
				}
				else {
					cur_left = 0;
				}

				if (cur_left == prev_left) {
					cur_time += 4;
				}
				else {
					cur_time += 2;
				}
				prev_left = cur_left;
			}

			time += cur_time;
			if (cnt[s] > 1) {
				time -= cur_time/2;
			}
		}

		cout << time << endl;
	}

	return 0;
}