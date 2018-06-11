/* 	Problem Link : http://codeforces.com/problemset/problem/455/A
	Problem Name : Boredom
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef long long ll;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define pb push_back

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n,x,maxi = -1;  // maxi for the max element in the array
	vi count(100010,0);
	vector <ll> dp;
	
	cin >> n;

	fl(i,0,n){
		cin >> x;
		count[x] ++ ; 
		if(x > maxi)
			maxi = x;
	}

	// dp[i] represents the answer if only numbers in the range 1 to i existed in the array
	dp.pb(0); 				// dp[0] = 0
	dp.pb(count[1]);	 	// dp[1] = count[1]
	fl(i,2,maxi+1){
		dp.pb(max(dp[i-1], dp[i-2] + 1LL*count[i]*i)); // since count is integer vector, converting to long long
	}

	// since array consists of no in the range 1 to maxi, the answer is dp[maxi]
	cout << dp[maxi];

	/*
	cout << "\n";
	fl(i,1,maxi+1){
		cout << dp[i] << " ";
	}
	*/
	return 0;
}