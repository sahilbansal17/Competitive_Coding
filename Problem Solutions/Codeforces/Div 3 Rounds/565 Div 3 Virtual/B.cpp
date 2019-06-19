#include <iostream>
#include <vector>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

class BMergeIt {
 public:
  void solve(std::istream &cin, std::ostream &cout) {
    int n;
    cin >> n;

    vector<int> a(n, 0);
    int moduloCount[3] = {0};
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      moduloCount[a[i] % 3]++;
    }
    int res = moduloCount[0];
    int pairs = min(moduloCount[1], moduloCount[2]);
    moduloCount[1] -= pairs;
    moduloCount[2] -= pairs;
    int triples = moduloCount[1] / 3 + moduloCount[2] / 3;
    res += (pairs + triples);
    cout << res << endl;
  }
};

int main() {

  FAST_IO;

  BMergeIt solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  int n;
  in >> n;
  for (int i = 0; i < n; ++i) {
    solver.solve(in, out);
  }

  return 0;
}