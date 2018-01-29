/* 	author		: 	sahilbansal17
	date		:	27th Jan, 2018	
	Works for Sub-Task 1 and 2.
*/
#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,k;

	cin >> n >> k;

	vi a(n);
	vi ht(10001,0); // 100*100 = 10^4
	rep(i,n){
		cin >> a[i];
	}

	rep(i,n){
		int min = a[i], x_r = 0, res;
		fl(j,i,n){
			if(a[j] < min){
				min = a[j];
			}
			x_r = x_r ^ a[j];
			res = x_r * min;
			// cout << res << "\n";
			ht[res] ++;
		}
	}
	int current_count = 0;
	rep(i,10001){
		current_count += ht[i];
		if(current_count >= k){
			cout << i;
			return 0;
		}
	}


	return 0;
}