//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to find out the Greatest common divisor of 2 numbers
#include <iostream>
using namespace std;

//Naive algorithm for finding GCD
//this loop starts from 2 to a+b
//where a & b are 2 numbers
int gcdNaive(int a, int b) {
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

int main() {
  int a, b;
  //Get's the input from the user
  cout<<"Enter the 2 numbers: ";
  cin >> a >> b;
  
  //Our Euclid's algorithm is precise about first and 2nd arguements
  if(a>b){
  	cout<<"GCD by Euclid's Algorithm is :"<<gcd(a,b)<<endl;
  }
  else{
  	cout<<"GCD by Euclid's Algorithm is :"<<gcd(b,a)<<endl;;
  }
  
  cout<<"GCD by naive algorithm is :"<<gcd(a, b)<<endl;
  
  return 0;
}

//Time and Space Complexities--------
//gcdNaive() function:- 
	//Time Complexity: O(n) actually it is O(a+b) for two numbers a and b as loops runs a+b times which is covered in O(n).
	//Space Complexity: O(1)
	
//gcd() function:-
	//Time Complexity: O(1) this is the ain advantage of Euclid's algorithm that it gives the esult in constant amount of time
	//Space Complexity: O(1)
