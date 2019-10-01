/* 
 * Solves the small test case for Problem A
 */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
typedef long long ll;
int main(){
  FAST_IO;
  int t;
  cin >> t;

  for (int i = 1; i <= t; ++i) {
    int r, c, sr, sc; // sr, sc: start row and column
    int er, ec; // end row and column
    int n; // no. of instructions
    cin >> n >> r >> c >> sr >> sc;

    int currentRow = sr;
    int currentCol = sc;

    string instructions;
    cin >> instructions;

    set<pair<int, int>> visited;
    visited.insert({sr, sc});

    for (int j = 0; j < n; ++j) {
      switch(instructions[j]) {
        case 'N':
          while (visited.find({currentRow, currentCol}) != visited.end()) {
            --currentRow;
          }
          break;
        case 'S':
          while (visited.find({currentRow, currentCol}) != visited.end()) {
            ++currentRow;
          }
          break;
        case 'E':
          while (visited.find({currentRow, currentCol}) != visited.end()) {
            ++currentCol;
          }
          break;
        case 'W':
          while (visited.find({currentRow, currentCol}) != visited.end()) {
            --currentCol;
          }
          break;
      }
      // cerr << currentRow << " " << currentCol << endl;

      visited.insert({currentRow, currentCol});
    }

    er = currentRow;
    ec = currentCol;

    cout << "Case #" << i << ": " << er << " " << ec << endl;
  }  

  return 0;
}
