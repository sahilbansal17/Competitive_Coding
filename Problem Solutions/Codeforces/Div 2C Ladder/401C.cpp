/* 	Problem Link : http://codeforces.com/problemset/problem/401/C
	Problem Name : Team
*/

#include <bits/stdc++.h>

using namespace std;

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n,m;
	cin >> n >> m; // n - number of zeroes, m - number of ones

	if(m < n - 1 || m > 2*n + 2){
		cout << "-1";
	}
	else{
		if(n == m+1){
			// only case when n is more than m, directly reduced to m = n 
			cout << "0";
			n -= 1;
		}
		while(m-n != 0 && n != 0){
			// trying to reduce to the case m = n 
			cout << "110";
			m -= 2;
			n -= 1;
		}
		if(n != 0){
			// reduced to m = n case
			fl(i,0,n){
				cout << "10";
			}
		}
		else{
			// now only possible that m = 0,1,2
			if(m == 1){
				cout << "1";
			}
			else if(m == 2){
				cout << "11";
			}
		}
	}
	return 0;
}