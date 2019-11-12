#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int search(const vector<int> &A, int B);
};
int Solution::search(const vector<int> &A, int B) {
    int n = A.size();
    int low = 0;
    int high = n - 1;
    int mid;
    while (low < high) {
        mid = low + ((high - low)>>1);
        if (A[mid] > A[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    int idx = low;
    
    bool res1 = binary_search(A.begin(), A.begin() + idx, B);
    bool res2 = binary_search(A.begin() + idx, A.end(), B);
    
    if (res1) {
        return (lower_bound(A.begin(), A.begin() + idx, B) - A.begin());
    } else if (res2) {
        return (lower_bound(A.begin() + idx, A.end(), B) - A.begin());
    } else {
        ;
    }
    return -1;
}

int main() {
    const vector<int> A = {4, 6, 8, 11, 13, 15, 0, 1, 2, 3};

    Solution solver;
    cout << solver.search(A, 10) << endl; // -1
    cout << solver.search(A, 3) << endl; // 9
    cout << solver.search(A, 4) << endl; // 0
    cout << solver.search(A, 16) << endl; // -1
}