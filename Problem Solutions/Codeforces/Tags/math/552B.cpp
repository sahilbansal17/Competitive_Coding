#include <bits/stdc++.h>

using namespace std;

/* Template file (modified) for Online Algorithmic Competitions */
/* Typedefs */
	/* Basic types */
	typedef long long ll;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n;
	cin >> n;

	/* We need to find out the number of digits required to 
  	   write down all the numbers from 1 to n.
  	   eg if n = 16
  	   we need 1*9 + 2*7 = 23 digits.

  	   The approach is very simple, as there is a pattern involved:
  	   Numbers from 1 to 9 (9 numbers) require one digit.
  	   Numbers from 10 to 99 (90 numbers) require two digits.
  	   Numbers from 100 to 999 (900 numbers) require three digits.
  	   ...
  	   All numbers in the range 10^n to 10^(n+1) - 1 require (n + 1) digits.

  	   Thus, we first find out the number of digits in n. That would help us certainly.
  	   Let us assume there are k digits.
  	   Then, all the numbers in the range 10^(k - 1) to n would require k digits.
  	   We then move backwards i.e. 10^(k - 2) to 10^(k - 1) require (k - 1) digits.
  	   So, the result till this stage = (n - 10^(k - 1) + 1)*k + (10^(k - 1) - 1 - 10^(k - 2) + 1)*(k - 1)
  	   We can continue till we take into account the numbers from 1 to 9
  	   and keep adding the required digits into the result.
	*/

	ll result = 0;
	/* create a copy to calculate the number of digits */
	int copy_n = n, num_dig = 0;
	while(copy_n){
		copy_n /= 10;
		num_dig ++;
	}

	result = (n - pow(10, num_dig - 1) + 1)*num_dig;
	int current_pow = num_dig - 1;
	while(current_pow > 0){
		result += (pow(10, current_pow) - pow(10, current_pow - 1))*(current_pow);
		current_pow --;
	}

	cout << result;

	/* There could be a better implementation of this problem
	   considering the mathematics and summing up the series
	   manually and writing down a closed expression.
	*/

	return 0;
}