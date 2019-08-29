/*
 * Problem link: https://leetcode.com/problems/reveal-cards-in-increasing-order/
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    // yet to complete
    return {};
  }
};

int main() {
  vector<int> input = {17, 13, 11, 2, 3, 5, 7};

  Solution solver;
  vector<int> output = solver.deckRevealedIncreasing(input);
  for (auto element: output) {
    cout << element << " ";
  }
  cout << endl;

  return 0;
}