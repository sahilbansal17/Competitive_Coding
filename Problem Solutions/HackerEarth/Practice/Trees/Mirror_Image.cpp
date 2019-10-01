/*
 * Problem Link: https://www.hackerearth.com/practice/data-structures/trees/binary-and-nary-trees/practice-problems/algorithm/mirror-image-2/
 */

#include <bits/stdc++.h>
using namespace std;

char alter(char ch) {
  if (ch == 'L') {
    return 'R';
  }
  return 'L';
}
int main() {
  int n, q;
  cin >> n >> q;

  int x, y;
  char p;

  map<int, pair<int, char>> parent;
  parent[1] = {1, '0'};
  map<pair<int, char>, int> next;
  for (int i = 0; i < n - 1; ++i) {
    cin >> x >> y >> p;
    parent[y] = {x, p};
    next[{x, p}] = y;
  }

  for (int i = 0; i < q; ++i) {
    cin >> x;
    if (x == 1) {
      cout << "1" << endl;
      continue;
    }
    string seq;
    while (parent[x].first != 1) {
      seq += parent[x].second;
      x = parent[x].first;
    }
    seq += parent[x].second;
    reverse(seq.begin(), seq.end());

    int cur = 1;
    int ptr = 0;
    while (ptr < seq.length() && next[{cur, alter(seq[ptr])}]) {
      cur = next[{cur, alter(seq[ptr])}];
      ++ptr;
    }
    if (ptr != seq.length()) {
      cout << "-1" << endl;
    } else {
      cout << cur << endl;
    }
  }
  return 0;
}