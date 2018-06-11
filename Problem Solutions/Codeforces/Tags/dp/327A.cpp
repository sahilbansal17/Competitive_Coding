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


int a[101];
int change[101];

/* Function declarations */


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
	
	int n, maxSubArraySum = 0, currentSubArraySum = 0, countOne = 0;

	cin >> n;

	rep(i, n){
		cin >> a[i];
		if(a[i] == 0){
			change[i] = 1;
		}
		else{
			countOne ++;
			change[i] = -1;
		}
		if(change[i] == 1){
			currentSubArraySum += 1;
			if(currentSubArraySum > maxSubArraySum){
				maxSubArraySum = currentSubArraySum;
			}
		}
		else if(currentSubArraySum != 0){
			currentSubArraySum -= 1;
		}
	}
	/* Corner Case: 
	 * When there are all ones then maxSubArraySum = 0
	 * but still, we have to atleast do one move
	 * so result will be countOne - 1 */
	if(countOne == n){
		cout << n - 1 << "\n";
		return 0;
	}
	cout << maxSubArraySum + countOne;
	return 0;
}

/* Submitted - 
 * on Date: 6th June, 2018 
 * at Time: 12:20 am IST
 * Problem Link - http://codeforces.com/problemset/problem/327/A
 */
