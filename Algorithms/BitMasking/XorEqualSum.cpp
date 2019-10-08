#include <bits/stdc++.h>
// Author: @NavonilDas
using namespace std;

/**
 * Problem: We need to find the number of ways such that a^b = a + b
 * this is only possible if a&b = 0 (How See the logic how to add two numbers without addition operator)
 * a&b = 0 if all the bits set on a are unset on b
 * example 10=1010 => 0X0X where X can be 0/1
 * hence 1010 & 0101 = 0, 1010&0000 = 0 etc. there will total 2^2 ways 
 * if a is already given all we need to do is count the number of bits which are not set (0)
 * number of ways = 2^(count all the bits which are not set)
 * */

long waysXorEqSum(long  n){
    int no_of_zeros = 0;
    while(n) {
        // Count if bit is equal to zero
        if((n & 1) == 0)
            ++no_of_zeros;
         n>>=1; // n /= 2
    }
    // 2^no_of_zeros is equal to left shifting 1 no_of_zeros times
    return 1<<no_of_zeros;
}

int main(){
    cout<<waysXorEqSum(10)<<endl;
    cout<<waysXorEqSum(1000)<<endl;
    return 0;
}