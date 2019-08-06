#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 public:
  int solve(int n) {
    string s;
    int x;
    int res = 0;
    stack<int> st;
    int cnt = 1;
    for (int i = 0; i < 2*n; ++i) {
      cin >> s;
      if (s == "add") {
        cin >> x;
        st.push(x);
      } else {
        if (!st.empty()) {
          if (st.top() == cnt) {
            st.pop();
          } else {
            ++res;
            while (!st.empty()) {
              st.pop();
            }
          }
        }
        ++cnt;
      }
    }
    return res;
  }
};

int main() {

  FAST_IO;
  int n;
  cin >> n;
  Solution solver;
  int res = solver.solve(n);
  cout << res << endl;
  return 0;
}