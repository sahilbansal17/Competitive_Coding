#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
typedef long long ll;

class Solution {
 private:
  priority_queue<int, vector<int>, greater<int>> pq;
  vector<string> res;
  void insert(int x) {
    pq.push(x);
    res.push_back("insert " + to_string(x));
  }
  void getMin(int x) {
    assert(pq.top() == x);
    res.push_back("getMin " + to_string(x));
  }
  void removeMin() {
    assert(pq.empty() == 0);
    pq.pop();
    res.push_back("removeMin");
  }
 public:
  vector<string> solve(int n) {
    string s;
    int x;
    for (int i = 0; i < n; ++i) {
      cin >> s;
      if (s == "insert") {
        cin >> x;
        insert(x);
      } else if (s == "getMin") {
        cin >> x;
        if (!pq.empty() && pq.top() > x) {
          insert(x);
          getMin(x);
        } else if (!pq.empty() && pq.top() < x) {
          while(!pq.empty() && pq.top() < x) {
            removeMin();
          }
          if (pq.empty() || pq.top() != x) {
            insert(x);
            getMin(x);
          } else if (pq.top() == x) {
            getMin(x);
          }
        } else if (!pq.empty() && pq.top() == x) {
          getMin(x);
        } else {
          // pq is empty
          insert(x);
          getMin(x);
        }
      } else {
        if (pq.empty()) {
          insert(1);
        }
        removeMin();
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
  vector<string> res = solver.solve(n);
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << endl;
  }
  return 0;
}