#include <iostream>
#include <cmath>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long ll;
const ll MOD = 1000000007LL;
const ll MAX = 100010LL;

template<typename T>
T gcd(T a, T b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

template<typename T>
T power(T x, T y) {
  T ans = 1;
  while (y > 0) {
    if (y & 1LL) {
      ans = (ans * x);
    }
    y >>= 1LL;
    x = (x * x);
  }
  return (ans);
}

class AFillingShapes {
 public:
  void solve(std::istream &cin, std::ostream &cout) {
    ll n;
    cin >> n;

    if (n % 2 == 0) {
      cout << power(2ll, n / 2) << endl;
    } else {
      cout << "0" << endl;
    }
  }
};

int main() {

  FAST_IO;

  AFillingShapes solver;
  std::istream &in(std::cin);
  std::ostream &out(std::cout);
  solver.solve(in, out);

  return 0;
}