#include <iostream>
// Author: @NavonilDas
using namespace std;

// Flip Bits for 32 bit number
// we use 0xFFFFFFFF for 32 bit numbers in this all bits are set
// if we xor it with any number the one will become zero and zero will become one
// example 5=> 0101 => 0101 ^ 1111 => 1010 (taking 4 bit numbers)
unsigned int flipBits(unsigned int a){
    return a ^ 0xFFFFFFFF;
}
// Alternative method iterate over the number of bits
// and convert number to decimal if bit is zero
long flipBits2(long n) {
    long res = 0,base = 1;
    for(int i=0;i<=31;++i){
        if(((n>>i)&1) != 1){
            res += base;
        }
        base *= 2l;
    }
    return res;
}

/*
* if a Number(n) is power of 2 its only one bit is set
* ex 8 => 1000, 16 => 10000
* if n is power of 2 then n-1 will be all one after the bit which
* was set when n was power of 2
* example 8 => 1000 ,(8-1) = 7 => 0111
* n&(n-1) will return zero if n is power of 2
* this case only fails when n=0 as 0&<any_number> = 0
* Not of zero return one
*/
bool isPower2(int a){
    return a && !(a&(a-1));
}

int main()
{
    if(isPower2(8))
        cout<<"8 is Power of 2\n";

    if(!isPower2(999))
        cout<<"999 is not a Power of 2\n";

    cout<<flipBits(802743475)<<endl;
    cout<<flipBits(802743475)<<endl;
   return 0;
}