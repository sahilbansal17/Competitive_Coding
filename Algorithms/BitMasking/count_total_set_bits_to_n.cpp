//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to count the sum of number of Set bits from 1 to input number nc
#include<iostream>

using namespace std;
 
// noOfSetBits() function  to count set bits 
// in a number x
//it's a helper function to SumOfSetBits() function
unsigned int noOfSetBits(unsigned int x)
{
    if (x <= 0)
        return 0;
    return (x % 2 == 0 ? 0 : 1) + noOfSetBits(x / 2);
}

//it returns the sum of set bits form 1 to n(given number)
unsigned int SumOfSetBits(unsigned int n)
{
    int bitCount = 0; // initialize the result
 	
 	//iterate over to the given number
    for (int i = 1; i <= n; i++)
        bitCount += noOfSetBits(i);
 	
 	//returning the bitCountSum
    return bitCount;
}
 
//main function that drives the program

int main()
{
	cout<<"Enter the number : ";
	int n;
	cin>>n;
	cout<<"Sum of set bits from 1 to "<< n <<" is : "<<SumOfSetBits(n)<<endl;
	return 0;
}
