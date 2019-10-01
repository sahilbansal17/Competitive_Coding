/* 
 * Solves the large test case for Problem A
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

    set<int> visitedR[r + 1];
    set<int> visitedC[c + 1];
    visitedR[sr].insert(sc);
    visitedC[sc].insert(sr);

    for (int j = 0; j < n; ++j) {
      switch(instructions[j]) {
        case 'E':
          for (int nextCol = currentCol + 1; nextCol <= c; ++nextCol) {
            if (visitedC[nextCol].find(currentRow) == visitedC[nextCol].end()) {
              currentCol = nextCol;
              visitedC[nextCol].insert(currentRow);
              visitedR[currentRow].insert(nextCol);
              break;
            }
          }
          break;
        case 'W':
          for (int nextCol = currentCol - 1; nextCol >= 1; --nextCol) {
            if (visitedC[nextCol].find(currentRow) == visitedC[nextCol].end()) {
              currentCol = nextCol;
              visitedC[nextCol].insert(currentRow);
              visitedR[currentRow].insert(nextCol);
              break;
            }
          }
          break;
        case 'N':
          for (int nextRow = currentRow - 1; nextRow >= 1; --nextRow) {
            if (visitedR[nextRow].find(currentCol) == visitedR[nextRow].end()) {
              currentRow = nextRow;
              visitedR[nextRow].insert(currentCol);
              visitedC[currentCol].insert(nextRow);
              break;
            }
          }
          break;
        case 'S':
          for (int nextRow = currentRow + 1; nextRow <= r; ++nextRow) {
            if (visitedR[nextRow].find(currentCol) == visitedR[nextRow].end()) {
              currentRow = nextRow;
              visitedR[nextRow].insert(currentCol);
              visitedC[currentCol].insert(nextRow);
              break;
            }
          }
          break;
      }
      // cerr << currentRow << " " << currentCol << endl;
    }

    er = currentRow;
    ec = currentCol;

    cout << "Case #" << i << ": " << er << " " << ec << endl;
  }  

  return 0;
}
