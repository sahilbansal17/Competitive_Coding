/* 	author		: 	sahilbansal17
	date		:	27th Jan, 2018	
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

	int T,n;
	cin >> T;

	while(T--){
		cin >> n;
		vi a(n);
		int odd = 0 , even = 0, res = 0;
		rep(i,n){
			cin >> a[i];
			if(a[i] & 1){
				odd++;
			}
			else{
				even ++;
			}
		}
		if(odd & 1){
			res += 1;
			odd --;
		}
		if(odd || even){
			res ++;
		}
		cout << res << "\n";
	}

	return 0;
}