/* 	author 	: 	sahilbansal17
	date	:	21st Jan, 2018	
*/

#include <bits/stdc++.h>

using namespace std;


int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t,n,k,s,res;

	cin >> t;

	while(t--){
		cin >> n >> k >> s;

		if(n >= k && s < 7){
			res = ceil((1.0*k*s)/n);
		}
		else if(n < k || ((n == k) && s > 7) ){
			res = -1;
		}
		else{
			if(n*6 - k*7 < 0){
				res = -1;
			}
			else{
				res = ceil((1.0*k*s)/n);
			}
		}
		cout << res << "\n";
	}

	return 0;
}