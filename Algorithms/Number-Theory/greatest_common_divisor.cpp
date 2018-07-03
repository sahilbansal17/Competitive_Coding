//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to find out the Greatest common divisor of 2 numbers
#include <iostream>
using namespace std;

//Naive algorithm for finding GCD
//this loop starts from 2 to the minimum of a and b
//where a & b are 2 numbers
int gcdNaive(int a, int b) {
	
	//in this algorithm we initialized the gcd with 1
	//and run the loop from d=2 to the minimum of a and b
	//in running the loop if for any value of d is factor of both a nad b
	//the tha value is greater than the prev value of gcd then it will be updated.
	int current_gcd = 1;
	for (int d = 2; d <= a && d <= b; d++) {
		if (a % d == 0 && b % d == 0) {
    		if (d > current_gcd) {
        		current_gcd = d;
      		}
    	}
  }
  return current_gcd;
}

//Euclid's algorithm for finding GCD
//this algo is simmilar to that we studied in shools for finding hcf
int gcd(int a, int b)
{
	//in this method of finding gcdfirst we divide the big of two numbers with smaller one
	//if the remainder comes out to be  0 then th gcd is smaller number othewise
	//we divide the the smaller number by the remainder that we got i.e the divisor is to be divided by the remainder
	//we continue to do that until we get remainder 0 and we will return the dvisor when remainer becomes zero
	int r=a%b;
	//base case for recursion
	if(r==0)
	{
		return b;
	}
	//calling of recursion on smaller problem
	else{
		return gcd(b,r);
	}
	
}


int main() {
  int a, b;
  //Get's the input from the user
  cout<<"Enter the 2 numbers: ";
  cin >> a >> b;
  
  //Our Euclid's algorithm is precise about first and 2nd arguements
  cout << "GCD by Euclid's algorithm is :" << gcd(a,b) << endl;
  
  cout << "GCD by naive algorithm is :" << gcdNaive(a, b) << endl;
  
  return 0;
}

//Time and Space Complexities--------
//gcdNaive() function:- 
	//Time Complexity: O(n) because the loop runs for the minimum of the two inputs.
	//Space Complexity: O(1)
	
//gcd() function:-
	//Time Complexity: 

	//O(logn) this is the main advantage of Euclid's algorithm that it has great complexity
	//the reccurence relation for the euclids algorithm is T(n) = T(n%10) + k  ; k is the constant amount of work
	//and by calculation we will get n/10^x= 1 which gives x= log n whic is the time complexity .
	//Consider any two steps of the algorithm.
	//At some point, you have the numbers (a,b)(a,b) with a>b. After the first step these turn to (b,c) with c=a mod b, 
	//and after the second step the two numbers will be (c,d) with d=b mod c.
	//Now think backwards. As d=b mod c, we know that b=kc+d for some k>0. The smallest possibility is k=1, therefore b≥c+d.
	//From that result and from a>b we get a>c+d. If we add the last two inequalities we just derived, we get that (a+b)>2(c+d).
	//In words, after each two consecutive steps the sum of the two numbers decreases to less than half of its original size.
	//Now look at the very first step of the algorithm. 
	//At the beginning, we have some (a,b) with a>b. After the very first step we have (b,c) with c=a mod b, and clearly b>c. 
	//Hence, after the very first step both numbers are at most equal to the smaller of the two input numbers.
	//Putting those two results together, we may conclude that the number of iterations (recursive calls in other implementations) 
	//is at most logarithmic in the smaller input number. In other words, the number of iterations is at most linear in 
	//the number of digits in the smaller input number. 

	//Space Complexity: O(1)

