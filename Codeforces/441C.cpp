/* 	Problem Link : http://codeforces.com/problemset/problem/441/C
	Problem Name : Valera and Tubes
*/

#include <bits/stdc++.h>

using namespace std;

#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n,m,k; 

	cin >> n >> m >> k;

	int i = 1, j = 1, tot = n*m, no = 2;

	if(k == 1){
		no = tot;
	}
	rep(q,k){
		cout << no << " ";
		rep(k,no){
			cout << i << " " << j << " ";
			if((i % 2 == 1 && j == m) || (i % 2 == 0 && j == 1)){
				i = i + 1;
			}
			else{
				if(i % 2 == 1){
					j ++;
				}
				else{
					j --;
				}
			}
		}
		cout << "\n";
		if(q == k-2){
			no = tot - (k-1)*2;
		}
	}

	return 0;
}