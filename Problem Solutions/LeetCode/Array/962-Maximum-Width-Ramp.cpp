/*
 * Problem link: https://leetcode.com/problems/maximum-width-ramp/
 */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 50010;
class Solution {
public:
  // Solution 1: O(N) considering array elements in range [0, 50000]
  int maxWidthRamp(vector<int>& a) {
    int highestAboveIndex[MAX] = {0};
    int n = a.size();
    int maxEle = 0;
    for (int i = 0; i < n; ++i) {
      int cur = a[i];
      highestAboveIndex[cur] = max(highestAboveIndex[cur], i);
      if (cur > maxEle) {
        maxEle = cur;
      }
    }
    for (int j = maxEle - 1; j >= 0; --j) {
      highestAboveIndex[j] = max(highestAboveIndex[j + 1], highestAboveIndex[j]);
    }

    int maxWidth = 0;
    for (int i = 0; i < n; ++i) {
      int cur = a[i];
      maxWidth = max(maxWidth, highestAboveIndex[cur] - i);
    }
    return maxWidth;
  }
  // Solution 2: O(N log N)
  int maxWidthRamp2(vector<int> &a) {
    int n = a.size();
    vector<pair<int, int>> withIndex(n);
    for (int i = 0; i < n; ++i) {
      withIndex[i] = {a[i], i};
    }
    sort(withIndex.begin(), withIndex.end());

    int minIndex = get<1>(withIndex[0]);
    int res = -1;
    for (int i = 1; i < n; ++i) {
      int curIndex = get<1>(withIndex[i]);
      minIndex = min(minIndex, curIndex);
      if (curIndex != minIndex) {
        res = max(res, curIndex - minIndex);
      }
    }
    return res;
  }
};

int main() {
  vector<int> input = {9,8,1,0,1,9,4,0,4,1};

  Solution solver;
  int output = solver.maxWidthRamp(input);
  cout << output << endl;

  return 0;
}