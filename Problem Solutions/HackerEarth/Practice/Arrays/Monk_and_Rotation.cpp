/*
 * Problem Link: https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/monk-and-rotation-3/
 */

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int j = 0; j < n; ++j) {
      cin >> a[j];
    }

    k %= n;
    int j = (n - k + n) % n;
    int done = 0;
    while (done != n) {
      cout << a[j] << " ";
      ++done;
      j = (j + 1) % n;
    }
    cout << endl;
  }
  return 0;
}