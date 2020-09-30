#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;
/**
 * Uncomment the #define below if problem contains multiple test cases
 */
#define MULTIPLE_TESTS 1
#define eps 1e-6
template <typename T>
inline void readArray(vector<T>& arr, int n) {
  arr.resize(n);
  for (auto& element : arr) {
    cin >> element;
  }
}

vector<ll> a;
ll n, l;

double find_time(double x, bool end) {
  double speed = 1;
  double time = 0;
  int i = 0;
  if (end) {
    double prev = l;
    i = n - 1;
    while(i >= 0 && a[i] >= x) {
      time += (prev - a[i])/speed;
      speed += 1;
      prev = a[i];
      --i;
    }
    time += (prev - x)/speed;
  } else {
    double prev = 0;
    while (i < n && a[i] <= x) {
      time += (a[i] - prev)/speed;
      speed += 1;
      prev = a[i];
      ++i;
    }
    time += (x - prev)/speed;
  }
  return time;
}
void solve() {
  cin >> n >> l;

  readArray(a, n);

  double low = 0.0, high = 1.0*l;
  double mid;
  while (abs(low - high) > eps) {
    mid = (low + high)/2.0;
    double t1 = find_time(mid, 0); // start
    double t2 = find_time(mid, 1); // end
    if (abs(t1 - t2) < eps) {
      cout << fixed << setprecision(20);
      cout << t1 << endl;
      return;
    }
    if (t1 < t2) {
      low = mid;
    } else {
      high = mid;
    }
  }
  cout << fixed << setprecision(20);
  cout << find_time(low, 0) << endl;
}

int main() {
  FAST_IO;
  int t = 1;
#ifdef MULTIPLE_TESTS
  cin >> t;
#endif

  while (t--) {
    solve();
  }

  return 0;
}