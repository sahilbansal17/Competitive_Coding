#include <bits/stdc++.h>
using namespace std;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/A-small-attempt3.in", "r", stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
	#endif

	int t, n, o;
	long long d, x1, x2, a, b, c, m, l;

	long long s[500001];

	long long current_odd, current_max, global_max;

	cin >> t;
	for(int i = 1; i <= t; i ++){
		cin >> n >> o >> d;
		cin >> x1 >> x2 >> a >> b >> c >> m >> l;
		s[0] = x1;
		s[1] = x2;
		// assuming l to be zero, small test case, only +ve values

		// calculate the sweetness values
		for(int j = 2; j < n; j ++){
			s[j] = (( (a * s[j - 1]) % m + (b * s[j - 2]) % m ) % m + (c % m) ) % m;
		}

		// initialize
		/*
		current_odd = (s[0] & 1) ? 1 : 0;
		if(current_odd == 1 && o >= 1 && s[0] <= d){
			current_max = s[0];
			global_max = s[0];
		}
		else if(current_odd == 0 && s[0] <= d){
			current_max = s[0];
			global_max = s[0];
		}
		else{
			current_max = 0;
			global_max = -1;
			current_odd = 0;
		}
		*/
		current_odd = 0;
		current_max = 0;
		global_max = -1;

		bool is_odd;
		for(int j = 0; j < n; j ++){
			// check whether odd
			if(s[j] & 1){
				is_odd = true;
			}
			else{
				is_odd = false;
			}

			// add s[i] to current max 
			if(is_odd && o >= current_odd + 1 && current_max + s[j] <= d){
				current_max = current_max + s[j];
				current_odd ++;
				if(current_max > global_max){
					global_max = current_max;
				}
			}
			else if(!is_odd && current_max + s[j] <= d){
				current_max = current_max + s[j];
				if(current_max > global_max){
					global_max = current_max;
				}
			} // make s[j] to be current_max
			else if(is_odd && o >= 1 && s[j] <= d){
				current_odd = 1;
				current_max = s[j];
				if(current_max > global_max){
					global_max = current_max;
				}
			}
			else if(!is_odd && s[j] <= d){
				current_odd = 0;
				current_max = s[j];
				if(current_max > global_max){
					global_max = current_max;
				}
			}
			else{
				current_max = 0;
				current_odd = 0;
			}
			// cout << global_max << " ";
		}

		cout << "Case #" << i << ": ";
		if(global_max > -1){
			cout << global_max << "\n";
		}
		else{
			cout << "IMPOSSIBLE\n";
		}
	}
	return 0;
}