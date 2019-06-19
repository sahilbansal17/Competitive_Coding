 #include <bits/stdc++.h>
using namespace std;

class AutomaticVacuumCleaner {
	public:
	long long getDistance(long long R, long long C, long long A, long long B) {
		ll x1 = A/C;
		ll y1 = A % C;
		ll x2 = (A + B)/C;
		ll y2 = (A + B) % C;

		if (y1 == 0) {
			x1 --;
		}
		if (y2 == 0) {
			x2 --;
		}

		if (x1 & 1) {
			y1 = C - y1;
			if (y1 == C) {
				y1 = 0;
			}
		}
		else {
			y1 --;
			if (y1 < 0) {
				y1 = C;
			}
		}
		if (x2 & 1) {
			y2 = C - y2;
			if (y2 == C) {
				y2 = 0;
			}
		}
		else {
			y2 --;
			if (y2 < 0) {
				y2 = C;
			}
		}

		return abs(x1 - x2) + abs(y1 - y2);
	}
};