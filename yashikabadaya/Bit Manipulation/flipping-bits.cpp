#include <iostream>

using namespace std;

// This program returns number with flipped bits.
long flippingBits(long n) {
    n = n ^ 4294967295;
    return n;

}

// Time Complexity: O(1), Since we are just xoring in the function.

// Space Complexity: O(1), Since we have not used any additional variable in the function.

int main()
{
  long n;
  cin >> n;
  cout << flippingBits(n);
}
