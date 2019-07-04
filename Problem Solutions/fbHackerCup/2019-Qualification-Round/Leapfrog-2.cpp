#include <iostream>
using namespace std;

typedef long long ll;

int main(){

	// #ifndef ONLINE_JUDGE
	// freopen("/Users/sahilbansal/Downloads/leapfrog_ch_.txt", "r", stdin);
	// freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	// freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
	// #endif

	int t;
	cin >> t;

	for (int k = 0; k < t; k ++) {
		string s;
		cin >> s;

		bool res = 1;

		int n = s.length();
		int dotCount = 0;
		int betaFrogCount = 0;
		for (int i = 1; i < n; i ++) {
			if (s[i] == '.') {
				dotCount ++;
			} else {
				betaFrogCount ++;
			}
		}

		if (dotCount == 0 || betaFrogCount < 2) {
			res = 0;
		}
		// for the case "AB."
		if (dotCount == 1 && betaFrogCount == 1) {
			res = 1;
		}

		cout << "Case #" << k + 1 << ": ";
		if (res) {
			cout << 'Y' << endl;
		} else {
			cout << 'N' << endl;
		}
	}	

	return 0;
}