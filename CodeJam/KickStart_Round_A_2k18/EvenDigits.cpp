/* 	
 	author		: 	sahilbansal17
	date		:	18th March, 2018	
*/

#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)
#define rfl(i,a,b) for(int i(a);i>=(b);i--)
#define srt(v) sort((v).begin(),(v).end())
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define slen(s) s.length()
#define F first
#define S second

ll solve(ll n){
	// find the minimum steps to reach a respresentation that has only even digits
	ll copy = n;
	// find the first odd digit 'd' and then that is to be replaced with either d+1 or d-1
	// for d+1, rest all after that should be 0
	// for d-1, rest all after that should be 8
	ll numP, numN, numBeforeOdd; // numP for d+1, numN for d-1
	int anyOdd = 0, powerOf10 = 0, leastOdd, mul_10;
	while(n){
		int rem = n%10;
		n = n/10;
		if(rem & 1){
			anyOdd = 1;
			leastOdd = rem;
			numBeforeOdd = n;
			mul_10 = powerOf10;
		}
		powerOf10 ++;
	}
	if(anyOdd == 0){
		// cout << "\n";
		return 0;
	}

	// need to handle the case when the least odd number (from left to right) is 9
	if(leastOdd == 9){
		numP = (numBeforeOdd*10 + 20)*pow(10, mul_10);	
	}
	else
		numP = (numBeforeOdd*10 + leastOdd + 1)*pow(10, mul_10);
	numN = (numBeforeOdd*10 + leastOdd - 1)*pow(10, mul_10); 

	// also need to append appropriate 8's at the end of numN
	ll eightNum = 0;
	while(mul_10){
		mul_10 --;
		eightNum *= 10;
		eightNum += 8;
	}
	numN += eightNum;
	// cout << numP << " " << numN << "\n" ;
	return min(numP - copy, copy - numN);
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	int t;
	ll n, res;
	cin >> t;  
	for (int i = 1; i <= t; ++i) {
		cin >> n;  
		res = solve(n);
		cout << "Case #" << i << ": " << res << endl;
	}

  return 0;
}