#include <bits/stdc++.h>
using namespace std;

#define fl(i, a, b)     for(int i(a); i < (b); i ++)
#define rep(i, n)       fl(i, 0, n)

int req_sum, cnt;
int track[20];

bitset <20> res;
int min_diff, max_taken = 0;

void solve (int i, int sum, bitset <20> taken) {

	if (i == cnt) {
		// all items considered
		int diff = req_sum - sum;
		if (diff >= 0 && diff == min_diff) {
			int taken_pres = 0;
			rep (i, cnt) {
				if (taken[i] == 1) {
					taken_pres ++;
				}
			}
			if (taken_pres >= max_taken) {
				max_taken = taken_pres;	
				min_diff = diff;
				res = taken;
			}
		}
		else if (diff >= 0 && diff < min_diff) {
			min_diff = diff;
			res = taken;	
		}
		// return;
	}
	else {
	// two options: either take the current item or don't take
	// solve (i + 1, sum);
	// solve (i + 1, sum + track[i]);

	// need to choose the one that will produce the min difference between sum and req_sum
	
		solve (i + 1, sum, taken);

		taken[i] = true;
		solve (i + 1, sum + track[i], taken);
	}

}

int main () {

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
	#endif

	// int ans;
	while (cin >> req_sum >> cnt) {
		// cin >> req_sum >> cnt;

		rep (i, cnt) {
			cin >> track[i];
		}

		bitset <20> taken;
		rep (i, cnt) {
			res[i] = false;
			taken[i] = false;
		}

		min_diff = INT_MAX;
		max_taken = 0;
		solve(0, 0, taken);

		rep (i, cnt) {
			if (res[i]) {
				cout << track[i] << " ";
			}
		}
		cout << "sum:" << req_sum - min_diff << endl; 
	}

}