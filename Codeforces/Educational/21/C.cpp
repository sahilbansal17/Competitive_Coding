#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                     \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
typedef long long ll;
// #define MULTIPLE_TESTS 1

template <typename T>
inline void readArray(vector<T>& arr, int n);
template <typename T>
inline void printArray(const vector<T>& arr);
template <typename T>
inline void sortArray(vector<T>& arr);
template <typename T>
inline T sumArray(const vector<T>& arr);
template <typename Container>
inline void sortContainer(Container& container);
template <typename T>
inline void withIdConstruction(vector<pair<T, T>>& with_id,
                               const vector<int>& arr);

void solve() {
  int n, w;
  cin >> n >> w;
  vector<int> arr;
  readArray(arr, n);
  vector<pair<int, int>> with_id;
  withIdConstruction(with_id, arr);
  sortContainer(with_id);
  vector<int> bucket(n, 0);
  for (int i = 0; i < n; ++i) {
    int cur = with_id[i].second;
    int value = with_id[i].first;
    bucket[cur] = ceil((1.0 * value) / 2);
  }
  int sum = sumArray(bucket);
  if (sum > w) {
    cout << -1 << endl;
    return;
  }
  int rem = w - sum;
  for (int i = n - 1; i >= 0; --i) {
    int cur = with_id[i].second;
    int value = with_id[i].first;
    int add = min(rem, value - bucket[cur]);
    bucket[cur] += add;
    rem -= add;
  }
  if (rem == 0) {
    printArray(bucket);
  } else {
    cout << -1 << endl;
  }
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

template <typename T>
inline void readArray(vector<T>& arr, int n) {
  arr.resize(n);
  for (auto& element : arr) {
    cin >> element;
  }
}
template <typename T>
inline void printArray(const vector<T>& arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; ++i) {
    cout << arr[i] << " ";
  }
  cout << arr[n - 1] << endl;
}
template <typename T>
inline void sortArray(vector<T>& arr) {
  sort(arr.begin(), arr.end());
}
template <typename Container>
inline void sortContainer(Container& container) {
  sort(container.begin(), container.end());
}
template <typename T>
inline void withIdConstruction(vector<pair<T, T>>& with_id,
                               const vector<int>& arr) {
  for (int idx = 0; idx < arr.size(); ++idx) {
    with_id.push_back({arr[idx], idx});
  }
}
template <typename T>
inline T sumArray(const vector<T>& arr) {
  T sum = accumulate(arr.begin(), arr.end(), 0);
  return sum;
}