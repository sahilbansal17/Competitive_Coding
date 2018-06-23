#include <bits/stdc++.h>

using namespace std;

/* Template file (modified) for Online Algorithmic Competitions */
/* Typedefs */
	/* STL containers */
	typedef vector <int> vi;
/* Macros */
	/* Loops */
	#define fl(i,a,b) for(int i(a);i<(b);i++)
	#define rep(i,n) fl(i,0,n)
	/* Shorthand notations */
	#define MAX 100010
	
int main(){

	/*
	
		In this problem, we just have to count the distinct numbers that are not equal to 0.
		Since the range of numbers is between -10^5 to +10^5, a hash table of size 2*10^5 is made
		When the number is first encountered, that entry in hash table is set to 1
		and the distinct_numbers variables is incremented only if that value in hash table is 0
	
		The hashing function is simply translation from +10^5 since that would do the job.
	*/
	int n;

	cin >> n;

	int a[MAX];

	vi hasht(200020, 0);

	int distinct_numbers = 0;

	rep(i, n){
		cin >> a[i];
		if(hasht[a[i] + 100000] == 0 && a[i] != 0){
			hasht[a[i] + 100000] = 1;
			distinct_numbers ++;
		}
		else{
			hasht[a[i] + 100000] = 1;
		}
	}	

	cout << distinct_numbers;
	return 0;
}