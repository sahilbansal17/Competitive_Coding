/*
 * Problem link: https://leetcode.com/problems/reveal-cards-in-increasing-order/
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> deckRevealedIncreasing(vector<int>& deck) {
    sort(deck.begin(), deck.end());
    int n = deck.size();
    vector<int> res(n); // to hold the answer
    queue<int> index;
    // add all indices in the queue
    for (int i = 0; i < n; ++i) {
      index.push(i);
    }

    // sort the deck cards
    sort(deck.begin(), deck.end());

    // simulate the process
    for (auto card: deck) {
      // place the card at the index present at top of the queue
      int idx = index.front();
      res[idx] = card;
      // pop the top index
      index.pop();
      // pop the second index and push at the end
      index.push(index.front());
      index.pop();
    }

    return res;
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