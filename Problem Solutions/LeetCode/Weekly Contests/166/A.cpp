#include <iostream>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1, sum = 0;
        while (n) {
            prod *= (n % 10);
            sum  += (n % 10);
            n /= 10;
        }
        return prod - sum;
    }
};

int main() {
    Solution solver;
    cout << solver.subtractProductAndSum(4421) << '\n';
    return 0;
}