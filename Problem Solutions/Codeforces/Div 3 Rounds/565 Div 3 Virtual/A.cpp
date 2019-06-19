#include <iostream>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;

class ADivideIt {
 public:
  void solve(std::istream &cin, std::ostream &cout) {
    ll n;
    cin >> n;

    int steps = 0;
    while (n > 1) {
      if (n % 2 == 0) {
        n /= 2;
      } else if (n % 3 == 0) {
        n /= 3;
        n *= 2;
      } else if (n % 5 == 0) {
        n /= 5;
        n *= 4;
      } else {
        cout << "-1" << endl;
        return;
      }
      steps++;
    }
    cout << steps << endl;
  }
};

int main() {

  FAST_IO;

  ADivideIt solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  int n;
  in >> n;
  for (int i = 0; i < n; ++i) {
    solver.solve(in, out);
  }

  return 0;
}