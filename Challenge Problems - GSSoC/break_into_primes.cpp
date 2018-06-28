/*
Given:
  A positive integer n > 1.
Tasks:
  Print a list of primes such that their sum is equal to n, maximize the number of primes in this list.
  Add proper explanations and time complexity.
Samples:
  2 - 2
  4 - 2+2
*/
#include <iostream>
using namespace std;

int main()
{
	int n, num_of_twos;
	cout<<"Enter number=";
	cin >> n;

	// Case 1: n is even
	if( n%2 == 0)
	{
		num_of_twos = n/2;
		for (int i = 0; i < num_of_twos; ++i)
		{
			cout<<"2 ";
		}
	}
	// Case 2: n is odd
	else
	{
		cout<<"3 ";
		num_of_twos = (n - 3)/2;
		for (int i = 0; i < num_of_twos; ++i)
		{
			cout<<"2 ";
		}
	}
	return 0;
}
// Case 1: Any even number can be represented as sum of twos as number is of the form 2m.
// Case 2: Odd numbers are of the form 2m+1. Now if we subtract 3 from the given number it becomes
// 		   2m-2 which is 2(m-1) again an even number and is again same as the previous case
// Also since 2 and 3 are smallest prime numbers this would maximise the number of prime numbers.

// Time complexity: loop runs at most (n/2) times so complexity is O(n)
// Space complexity : O(1)