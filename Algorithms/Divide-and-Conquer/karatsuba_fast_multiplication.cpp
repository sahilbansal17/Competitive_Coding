#include<iostream>
#include<stdio.h>
using namespace std;
//Name:Jyoti Mishra(@jstjyoti)
//E mail-jyotimishra29091997@gmail.com
 /*If the entered binary String are not Having same length then we have to append zeors(0) to MSB(right side) of smaller number and return the length 
 of equal binary numbers.
 Time Complexity of this Function is O(len1-len2+1) considering len1 and len2 as length of binary number strings.
 Space complexity is O(1) as only a few (constant number of variables are required 
*/
int AddZeros(string &s1, string &s2)
{
    int len1,len2,i;
	len1= s1.size();
    len2 = s2.size();
    if(len1 < len2)
    {
        for(i=0 ;i<len2 - len1;i++)
            s1 = '0' + s1;//Concatenating Zeros
        return len2;
    }
    else if (len1 > len2)
    {
        for (i = 0; i< len1-len2;i++)
            s2 = '0' + s2;
		return len1;
    }
    return len1; // If len1 == len2 then aany one of lengths to be returned
	//returned length is nothing but number of bits dividing which into smaller parts this algorithm works
}
 /*This is the function in which we will perform the full adder opertaion on each bits of the given string sequence with carry generated in previous step.
Time complexity of this Function is O(n) where n is equal length returned by the addZero function here.
Space Complexity is 
 */
string addBitStrings( string s1, string s2 )
{
    string r; // To store the sum bits
 
    // make the lengths same before adding
    int length = AddZeros(s1, s2);
    int carry = 0;  // Initially Carry is 0
 
    // Add all bits one by one
    for (int i = length-1 ; i >= 0 ; i--)
    {
        int firstBit = s1.at(i) - '0';
        int secondBit = s2.at(i) - '0';
 
        // Full adder sum expresion i.e., boolean expression for sum of 3 bits
        int sum = (firstBit ^ secondBit ^ carry)+'0';
 
        r = (char)sum + r;
 
	//full adder carry expression
	carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry);
    }
 
    // if overflow, then add a leading bit  1
    if (carry)  
		r = '1' + r;
 
    return r;
}
 
// A function to multiply single bits of strings b1 and b2
//Time Complexity is O(1) as Constant time Required and no extra space required for this function

int multiplyiSingleBit(string b1, string b2)
{ 
	return (b1[0] - '0')*(b2[0] - '0');  
}
 
/* This function that multiplies two bit strings b1 and b2 and returns the corrosponding Decimal form Result of the multi plication.
What it does is,Instead of multiplying entire n bits ,it Partions the strings into Two halves and then Multiplying. 
Dividing the numbers into two half becomes like (2^(n/2))*Left_half+Right_Half .
b1*b2=((2^(n/2))*b11+b1r)*((2^(n/2))*b21+b2r)
b1*b1=((2^n)b11*b21)+b1r*b2r+(2^(n/2))*[((b11+b1r)*(b21+b2r))-b11*b21-b1r*b2r]
let, P1=b11*b21 , P2=b1r*b2r and p3=((b11+b1r)*(b21+b2r))
so we get finally as,
b1*b1=((2^n)P1)+P2+(2^(n/2))*[P3-P1-P2]

Time Complexity is ,T(n)=3*T(n/2)+n [n for adding and shifting and since there are 3 multiplication of n/2 length numbers so T(n/2)]
Solving above time Complexity equation using master method we get T(n)=theta(n^((log3)base 2)
so we get a tight bound solution of order of (n^1.58) which is less than O(n^2)
	
This Algorithm has Constant Space Requirement so space Complexity is O(1).
*/
long int multiply(string b1, string b2)
{
    // Find the maximum of lengths of x and Y and make length
    // of smaller string same as that of larger string
    int n = AddZeros(b1, b2);
 
    if (n == 0) return 0;
    if (n == 1) return multiplyiSingleBit(b1, b2);
 
    int first= n/2;   // First half of string, floor(n/2)
    int second= (n-fh); // Second half of string, ceil(n/2)
 
    // Find the first half and second half of first string.
    //first half of b1 String
    string b1l = b1.substr(0, first);
	//Remaining of b1 String
    string b1r = b1.substr(first, second);
 
    // Find the first half and second half of second string
    string b2l = b2.substr(0, first);
    string b2r = b2.substr(first, second);
 
    // Recursively calculate the three products of inputs of size n/2
    long int P1 = multiply(b1l, b2l);
    long int P2 = multiply(b1r, b2r);
    long int P3 = multiply(addBitStrings(b1l, b1r), addBitStrings(b2l, b2r));
 
    // Combine the three products to get the final result.
    return P1*(1<<(2*second)) + (P3 - P1 - P2)*(1<<second) + P2;
}
/*
From Main function we take Input Streams in Binary Form in form of two Strings and then Call The multiply() function.
The Output is result of multiplication in decimal form .
The Overall Time Complexity Of this Program is asynmptotic tight bound of n^1.58 which is less than O(n^2).

*/
 int main()
 {
	string b1,b2;
	printf("Enter The first binary Number");
	scanf("%s",b1);
	printf("Enter The Second binary Number");
	scanf("%s",b2);
	printf("Multiplication result = %lld",multiply(b1,b2));
	return 0;
 }
