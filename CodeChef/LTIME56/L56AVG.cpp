/* 	author		: 	sahilbansal17
	date		:	27th Jan, 2018	
	Works for Sub-Task 1
*/
#include <bits/stdc++.h>

using namespace std;

#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)
#define srt(v) sort((v).begin(),(v).end())
#define MOD 1000000007

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int T,n,x,y,temp, flag, sum = 0;
	cin >> T;

	while(T--){
		sum = 0;
		cin >> n;
		fl(i,1,n+1){
			cin >> temp;
			sum += temp;
		}

		flag = 1;
		rep(i,n-1){
			cin >> x >> y;
			if(abs(x-y) != 1){
				flag = 0;
			}
		}
		if(flag == 1){
			// subtask 1
			double res = 1.0*sum/n;
			cout << setprecision(7);
			cout << fixed << res << "\n";
		} 
	}

	return 0;
}