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
	//Time Complexity: O(logn) this is the main advantage of Euclid's algorithm that it has great complexity
	//the reccurence relation for the euclids algorithm is T(n) = T(n%10) + k  ; k is the constant amount of work
	//to find time compexity we find the T(n%10) = T(n%100)+k and so on till T(1) and finally add all those expressions
	//and by calculation we will get n/10^x= 1 which gives x= log n whic is the time complexity .
	//we get above reccurrence relation because we reduce the problem  to n%10 every time that is one less decimal place        
	//Space Complexity: O(1)

