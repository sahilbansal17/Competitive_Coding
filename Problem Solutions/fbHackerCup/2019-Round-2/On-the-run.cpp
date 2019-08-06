#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000010;
const int MOD = 1000000007;
typedef long long ll;

// #define TEST 1
#define SUBMIT 1

class Solution {
 public:
  bool solve(int n, int m, vector<pair<int, int>> pos, int a, int b) {
    if (pos.size() == 1) {
      return 0;
    }
    int dist1 = abs(pos[0].first - a) + abs(pos[0].second - b);
    int dist2 = abs(pos[1].first - a) + abs(pos[1].second - b);
    // cerr << dist1 << " " << dist2 << endl;
    if (dist1 % 2 == 0 && dist2 % 2 == 0) {
      return 1;
    }
    return 0;
  }
};

int main(){

  ios_base::sync_with_stdio(false); 
  cin.tie(0); 
  cout.tie(0);

  #ifdef TEST
  freopen("/Users/sahilbansal/Desktop/input.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif

  #ifdef SUBMIT
  freopen("/Users/sahilbansal/Downloads/on_the_run.txt", "r", stdin);
  freopen("/Users/sahilbansal/Desktop/output.txt", "w", stdout);
  freopen("/Users/sahilbansal/Desktop/error.txt", "w", stderr);
  #endif 

  int t;
  cin >> t;

  Solution solver;
  for (int i = 0; i < t; i ++) {
    int n, m, k, x, y;
    cin >> n >> m >> k;
    int a, b;
    cin >> a >> b;

    vector<pair<int, int>> pos;
    for (int j = 0; j < k; j ++) {
      cin >> x >> y;
      pos.push_back({x, y});
    }

    bool res = solver.solve(n, m, pos, a, b);
    char ans = 'Y';
    if (!res) {
      ans = 'N';
    }
    cout << "Case #" << i + 1 << ": " << ans << endl;  
  } 

  return 0;
}