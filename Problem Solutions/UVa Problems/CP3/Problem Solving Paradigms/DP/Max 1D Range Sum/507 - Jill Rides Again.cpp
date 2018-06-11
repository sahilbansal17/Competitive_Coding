#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions (Lines 6 - 33) */
/* Typedefs */
	/* Basic types */
	typedef long long ll;
	typedef unsigned long long ull;
	/* STL containers */
	typedef vector <int> vi;
	typedef vector <ll> vll;
	typedef pair <int,int> pii;
	typedef pair <ll,ll> pll;
	typedef vector < pii > vpii;
	typedef vector < pll > vpll;
/* Macros */
	/* Loops */
	#define fl(i,a,b) for(int i(a);i<(b);i++)
	#define rep(i,n) fl(i,0,n)
	#define rep1(i,n) fl(i,1,n)
	#define rfl(i,a,b) for(int i(a);i>=(b);i--)
	/* Algorithmic functions */
	#define srt(v) sort((v).begin(),(v).end())
	/* STL container methods */
	#define pb push_back
	#define mp make_pair
	/* String methods */
	#define slen(s) s.length()
	/* Shorthand notations */
	#define F first
	#define S second
	#define MOD 1000000007
	#define MAX 20010

/* Global variable declarations */
/* dp[i] represents the maximum sum ending at a[i] */
int dp[MAX];
int length[MAX];
int a[MAX];

pii max1DRangeSum(int n){
	dp[0] = a[0];
	length[0] = 1; 
	rep1(i, n){
		if(dp[i - 1] >= 0){
			dp[i] = dp[i - 1] + a[i];
			length[i] = length[i - 1] + 1;
		}
		else{
			dp[i] = a[i];
			length[i] = 1;
		}
	}
	/* Constraints:
	 * If more than one subarray has same max sum, choose one with longer length,
	 * If more than one such subarray have same length, choose one starting earlier.
	 */

	int maxSumStart, maxSum = INT_MIN, maxLength = -MAX, maxSumEnd;
	rep(i, n){
		if(dp[i] > maxSum){
			maxSum = dp[i];
			maxLength = length[i];
			maxSumStart = i - length[i] + 1;
			maxSumEnd = i;
		}
		else if(dp[i] == maxSum && length[i] > maxLength){
			maxLength = length[i];
			maxSumStart = i - length[i] + 1;
			maxSumEnd = i;
		}
	}

	pii result;
	if(maxSum < 0){
		result = make_pair(0, 0);
	}
	else{
		result = make_pair(maxSumStart + 1, maxSumEnd + 2);
	}
	return result;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif
	
	int routes, stops, start, end;
	pii route;
	cin >> routes;

	rep(i, routes){
		cin >> stops;
		rep(j, stops - 1){
			cin >> a[j];
		}
		route = max1DRangeSum(stops - 1);
		start = route.F;
		end = route.S;
		if(start == 0){
			cout << "Route " << i + 1 << " has no nice parts\n";
		}
		else{
			cout << "The nicest part of route " << i + 1 << " is between stops " << start << " and " << end << "\n";
		}
		/*
		rep(i, stops - 1){
			cout << dp[i] << " ";
		}
		cout << "\n\n";
		//*/
	}
	return 0;
}