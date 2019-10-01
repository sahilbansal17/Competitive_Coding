#include <bits/stdc++.h>
// Author: @NavonilDas
using namespace std;

/***
 * Problem: Find maximum a xor b  in range l to r such that l <= a,b <= r
 * we know that maximum xor in the range 0 <= a,b <= 2^n is 2^n - 1 where n is a positive integer
 * so the answer between l and r will be dependent on the most significant bit of their xor
 * example l=10(1010) & r=15(1111) => l xor r =  (0101) the maximum xor that we can achieve is 2^3 - 1
 * where 3 is the position of most significant bit of l xor r
 * */

// Returns the position of MSB of n
int getMSB(int n){
    // n is a 32 bit number
    // Iterate from the 31st bit to 0th bit 
    for(int i=31;i>=0;--i)
        // Shift the bit till i th position and check the bit is 1 or not
        if((n>>i)&1) return i+1; // We are till zero so we need to add 1
    return 0;
}

int maxXor(int l,int r){
    int res = getMSB(l ^ r);
    // 2^res is equivalent to left shifing the 1 bit res time
    return (1 << res) - 1;
}

int main(){
    cout<<maxXor(10,15)<<endl;
    cout<<maxXor(11,101)<<endl;
    return 0;
}