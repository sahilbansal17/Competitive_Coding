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
	int r=a%b;
	//base case for recursion
	if(r==0)
	{
		return b;
	}
	//calling of ewcursion on smaller problem
	else{
		return gcd(b,r);
	}
	
}

//this is a helper function to gcd() function because our gcd function 
// is very precise about first and second arguements of function 
//in gcd() function first arguement should be greater so we made a helper function for this purpose
int gcdHelper(int a,int b){
	if(a>=b){
		return gcd(a,b);
	}
	else{
		return gcd(b,a);
	}
}

int main() {
  int a, b;
  //Get's the input from the user
  cout<<"Enter the 2 numbers: ";
  cin >> a >> b;
  
  //Our Euclid's algorithm is precise about first and 2nd arguements
  cout << "GCD by Euclid's algorithm is :" << gcdHelper(a,b) << endl;
  
  cout << "GCD by naive algorithm is :" << gcd(a, b) << endl;
  
  return 0;
}

//Time and Space Complexities--------
//gcdNaive() function:- 
	//Time Complexity: O(n) because the loop runs for the minimum of the two inputs.
	//Space Complexity: O(1)
	
//gcd() function:-
	//Time Complexity: O(1) this is the ain advantage of Euclid's algorithm that it gives the esult in constant amount of time
	//Space Complexity: O(1)
