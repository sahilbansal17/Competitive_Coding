class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double one = 1.00;
        double half = 0.50;
        if (n == 1) {
            return one;
        } else {
            return half;
        }
    }
};