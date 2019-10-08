#include <iostream>

using namespace std;

// This program returns the number of times sum and xor are equal.
long sumXor(long n) {
    long long no_of_unset_bits = 0;
    while(n){
        if((n & 1) == 0){
            no_of_unset_bits++;
        }
    n = n >> 1;
    }
    return (1 << no_of_unset_bits);
}

// Time Complexity: O(n), Since we are shifting each bit of n, n times in while loop.

// Space Complexity: O(1), Since we have just used an additional variable no_of_unset_bits inside the function.

int main()
{
    long n;
    cin >> n;
    cout << sumXor(n);

}