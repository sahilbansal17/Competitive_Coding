#include <iostream>

using namespace std;

// This program returns the maximum xor value possible from given range.
int maximizingXor(int l, int r) {
    int n = 0;
    for(int i = l; i <= r; i++){
        for(int j = l; j <= r; j++){
            if(n < (i ^ j)){
                n = i ^ j;
            }
        }
    }
    return n;

}

// Time Complexity: O(n^2), Since we are checking out all possible permutations.

// Space Complexity: O(1), Since we have used only one additional variable n in the function.

int main()
{

    int l;
    cin >> l;

    int r;
    cin >> r;

    int result = maximizingXor(l, r);

    cout << result << "\n";

    return 0;
}
