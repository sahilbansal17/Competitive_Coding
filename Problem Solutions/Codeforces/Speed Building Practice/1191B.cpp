#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(vector<pair<int, char>> cards) {
    map<pair<int, char>, int> count;
    int res = 3;
    int n = cards.size();
    for (int i = 0; i < n; ++i) {
      ++count[cards[i]];
    }
    // min to koutsu
    for (auto it: count) {
      // cerr << it.first.first << " " << it.first.second << endl;
      res = min(res, n - it.second);
    }
    for (int i = 0; i < n; ++i) {
      int number = cards[i].first;
      char suit = cards[i].second;
      int sequentialCount = 1;
      for (int j = 1; j <= 2; ++j) {
        if (count[{number + j, suit}] > 0) {
          ++sequentialCount;
        }
      }
      res = min(res, n - sequentialCount);
    }
    return res;
  }
};

int main() {

  FAST_IO;

  #ifndef ONLINE_JUDGE
  freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif
  
  vector<pair<int, char>> cards(3);
  for (int i = 0; i < 3; ++i) {
    scanf("%d%c ", &cards[i].first, &cards[i].second);
    // cerr << cards[i].first << " " << cards[i].second << endl;
  }

  Solution solver;
  cout << solver.solve(cards) << endl;
  return 0;
}