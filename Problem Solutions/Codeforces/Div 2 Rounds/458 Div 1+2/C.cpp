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

int dp[1005];
ll ncr[1005][1005];

/* Function declarations */
int ones(int n);
void calc_ncr();

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
	
	/* Step 1:
	 * Any possible input number n would reduce to a number with not more than 999 set bits
	 * so precompute the min. steps of first 1000 numbers (call it order)

	 * Step 2 (Thinking):
	 * Since the number n would reduce to a number less than 1000 in step 1
	 * and we wish to find all those numbers that reduce to 1 in k steps
	 * and are not larger than n.
	 * So, we reduce problem as to find the no. of numbers less than equal to n that reduce
	 * to a number x less than 1000 in the first step s.t. x has a order of k - 1.
	 * That means, that number would automatically reduce to 1 in k - 1 steps.
	 * So, we simply store for each number x less than 1000 with order k - 1, the 
	 * no. of numbers less than or equal to n that have 'x' set bits. 
	 
	 * Step 2 (Implementation):
	 * For doing it, we first precompute binomial coefficients and from C(1,1) till C(1000, 1000)
	 * Then, to get numbers less than or equal to n having 'x' set bits, 
	 * Let such a number be 'p' and n has 'k' bits in its binary representation
	 * so, we first choose i s.t. 1 ≤ i < k and i-th bit of n from left is 1
	 * now we copy binary representation of n uptil (i-1)th position (left->right) in 'p'
	 * we put 0 at i-th position of 'p', now definitely p will be smaller than n
	 * and to make sure that 'p' has x set bits, we have to choose 
	 * any (x - set_bits_encountered_in_n) bits from remaining (k - i) bits
	 * this is found by stored binomial coefficients.
	 * This process is iterated over all possible i's and for all x < 1000.
	 
	 * Step 3 (Final Result):
	 * Add up the values for all x's which gives total numbers less than or equal to n
	 * with order k. */

	string n;
	int k;
	cin >> n;
	cin >> k;

	/* Fill the binomial coefficients table */
	calc_ncr(); 

	/* Step 1 */
	dp[1] = 0; 
	fl(i, 2, 1001){
		/* Order of i = 1 + Order of set bits in i */
		dp[i] = dp[ones(i)] + 1;
	}

	ll res = 0, num_ones = 0;
	int len = slen(n); 
	/* Corner Case:
	 * if(k == 0) res = 1
	 * This will not hold true after going inside the loop
	 * as the value of res remains unchanged to 0 since dp[j] can never be -1 
	 * So, solution gets Wrong Answer verdict if this case is not handled */
	
	if(k == 0){
		/* n is always greater than or equal to 1, so 1 is always less than or equal to n
		 * and also 1 goes to 1 in zero steps */
		cout << "1\n";
		return 0;
	}

	/* Step 2 and 3 together
	 * Instead of saving result of step 2, it is continuously added
	 * to get the final result as in step 3. */

	rep(i, len){
		if(n[i] == '0'){
			/* continue since not favourable position for i */
			continue; 
		}
		/* otherwise if n has 1 at this position */
		int j = max(num_ones, 1LL); 
		while(j < 1000){
			if(dp[j] == k - 1){
				res = (res + ncr[len - i - 1][j - num_ones]) % MOD;
				/* The case when 1st position from left of n is 1
				 * and value of k is also 1
				 * so we need not consider the case 10000...0 */
				if(i == 0 && k == 1){
					res = (res + MOD - 1) % MOD;
				}
			}
			j ++;
		}
		/* increment in ones encountered in n */
		num_ones ++;
	}

	/* Check if n can reduce to 1 in k steps */
	int count = 0;
	rep(i, len){
		if(n[i] == '1'){
			count ++;
		}
	}
	if(dp[count] == k - 1){
		res = (res + 1) % MOD;
	}

	cout << res << "\n";

	return 0;
}

int ones(int n){
	int count = 0;
	while(n){
		if(n % 2 == 1){
			count ++;
		}
		n /= 2;
	}
	return count;
}

void calc_ncr(){
	rep(i, 1001){
		ncr[i][0] = 1;
	}
	rep1(i, 1001){
		rep1(j, i + 1){

			/* Use the identity:
			 * C(n, r) = C(n - 1, r - 1) + C(n - 1, r) */
			ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;

		}
	}
}
/* Submitted - 
 * on Date: 5th June, 2018 
 * at Time: 10:35 pm IST
 * Problem Link - https://codeforces.com/contest/914/problem/C
 */
