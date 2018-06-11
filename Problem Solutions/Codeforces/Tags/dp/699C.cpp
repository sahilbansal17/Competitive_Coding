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
	#define MAX 100010

/* Global variable declarations */
int day[101];
/* dp[i][j] denotes the max days of no rest if i-th day is chosen to be
 * j = 0 => rest day
 * j = 1 => contest day
 * j = 2 => sport day
 * j = 3 is not required */
int dp[101][3]; 

int main(){

	/* Input & Output from files for easy testing (Lines 54 - 57) 
	 * These lines do not affect the submission on Online Judges.
	 * Comment them if input is to be taken from stdin and 
	 * output is to be given to stdout. 
	 * If input and output is to be taken from file, then:
	 * Change the input file address as the first parameter of freopen on line 55.
	 * Change the output file address as the first parameter of freopen on line 56. */
	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif
	
	int n;
	cin >> n;

	rep(i, n){
		cin >> day[i];
	}

	/* To minimize the rest days, we maximize the days with no rest.
	 *
	 * dp[i][0] = max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2])
	 *
	 * if(i-th day is contest day)
	 * dp[i][1] = 1 + max(dp[i - 1][0], dp[i - 1][2])
	 * since previous day can be either rest day or sport day
	 *
	 * similarly, if(i-th day is sport day)
	 * dp[i][2] = 1 + max(dp[i - 1][0], dp[i - 1][1])
	 * 
	 * Now, to get the min days of rest
	 * in dp[n - 1] row, we need to take the max of the values
	 * and then subtract it from total no of days. 
	 * (Indexing of days and dp table starts from i = 0)
	 */

	/* Initialize with the 1st day 
	 * Be careful in this step! Prone to errors! */
	dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
	if(day[0] == 1){
		dp[0][1] = 1;
	}
	else if(day[0] == 2){
		dp[0][2] = 1;
	}
	else if(day[0] == 3){
		dp[0][1] = 1; dp[0][2] = 1;
	}

	rep1(i, n){
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
		if(day[i] == 1 || day[i] == 3){
			dp[i][1] = 1 + max(dp[i - 1][0], dp[i - 1][2]);
		}
		if(day[i] == 2 || day[i] == 3){
			dp[i][2] = 1 + max(dp[i - 1][0], dp[i - 1][1]);
		}
	}
	cout << n - max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
	return 0;
}

/* Submitted - 
 * on Date: 6th June, 2018 
 * at Time: 12:55 am IST
 * Problem Link - http://codeforces.com/problemset/problem/698/A
 */
