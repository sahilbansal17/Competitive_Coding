#include <bits/stdc++.h>

using namespace std;

/* Template file (modified) for Online Algorithmic Competitions */
/* Macros */
	/* Loops */
	#define fl(i,a,b) for(int i(a);i<(b);i++)
	/* String methods */
	#define slen(s) s.length()

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	/* Since the number is really huge, input is as a string */

	string number_string;
	cin >> number_string;


	/* We need to calculate 
	   (1^n + 2^n + 3^n + 4^n) mod 5

	   Since we cannot directly calcuate such huge powers, 
	   we know that any number modulo 5 is same as the 
	   last digit of that number modulo 5.

	   Thus, we have to first calculate the last digit of 
	   1^n + 2^n + 3^n + 4^n
	   which can be done by individually calculating the 
	   last digits of each of the terms and then adding them up
	   then taking modulo 10
	*/

	/* store the last digit of each of the powers in this array */
	int last_pow[5]; 

	/* since 1^n = 1 always */
	last_pow[1] = 1;

	/* since anything^0 = 1 */
	if(number_string == "0"){
		fl(i, 2, 5){
			last_pow[i] = 1;
		}
	}
	else{
		/* calculating last digits of 2^n, 3^n and 4^n is easy
		   we just have to identify the pattern and see what
		   is the periodicity after which last digit starts
		   repeating
		*/

		/* 2^n 
		   2^1 = 2
		   2^2 = 4
		   2^3 = 8
		   2^4 = 16
		   2^5 = 32 and here it starts repeating...
		   => periodicity = 4

		   Similarly, periodicity for 3 is 4 and for 4 it is 2.
		*/

		/*
			So, we need to know (n % 4) and (n % 2) values in order to 
			know the last digits.
			This looks tricky initally, since we cannot store n (huge) in 
			any integer format, so how do we calculate the modulo ?
			We just have to check whether the last digit is odd or even for 
			knowing (n % 2).
			For (n % 4), we know that any number is divisible by 4, if
			its last two digits are also divisible by 4.
			So, intuitively and mathematically, (n % 4) is same as 
			(number formed by last two digits of n) % 4.
		*/

		int digits_in_num = slen(number_string);
		int last_dig = number_string[digits_in_num - 1] - '0';
		int second_last_dig = 0;
		if(digits_in_num >= 2) second_last_dig = number_string[digits_in_num - 2] - '0';
		int number_formed_by_last_two_dig = second_last_dig*10 + last_dig;
		
		int modulo_two, modulo_four;
		modulo_two = last_dig % 2;
		modulo_four = number_formed_by_last_two_dig % 4;

		/* Calculating last digit of 2^n
		   (n % 4)	Last_Digit
		   0	6
		   1	2
		   2	4
		   3	8

		   Calculating last digit of 3^n
		   (n % 4) Last_Digit
		   0	1
		   1	3
		   3	9
		   4	7

		   For ease of implementation, we can calculate the last digit of 4^n
		   using (n % 4) instead of (n % 2)
		   (n % 4)	(n % 2)	Last_Digit
		   0	0	6
		   1	1	4
		   2	0	6
		   3	1	4
		*/
		switch(modulo_four){
			case 0:
				last_pow[2] = 6;
				last_pow[3] = 1;
				last_pow[4] = 6;
				break;
			case 1:
				last_pow[2] = 2;
				last_pow[3] = 3;
				last_pow[4] = 4;
				break;
			case 2:
				last_pow[2] = 4;
				last_pow[3] = 9;
				last_pow[4] = 6;
				break;
			case 3:
				last_pow[2] = 8;
				last_pow[3] = 7;
				last_pow[4] = 4;
				break;
		}
	}

	/* Calculate the last digit in the sums of the powers */
	int last_digit = 0;
	fl(i, 1, 5){
		last_digit += last_pow[i];
	}

	/* The final required value */
	int modulo_five;
	modulo_five = last_digit % 5;
	cout << modulo_five;

	/*
		After running this on several cases,
		I figured out that the answer is either 0 or 4
		if(n % 4 == 0) then the answer is 4
		otherwise the answer is 0.

		Try to figure out the logic, I am also going to do it now!
	*/
	return 0;
}