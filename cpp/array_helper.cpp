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
  if (n == 0) {
    return;
  }
  for (int i = 0; i < n - 1; ++i) {
    cout << arr[i] << " ";
  }
  cout << arr[n - 1] << endl;
}

template <typename T>
inline T sumArray(const vector<T>& arr) {
  T sum = accumulate(arr.begin(), arr.end(), 0);
  return sum;
}

template <typename Container>
inline void sortContainer(Container& container) {
  sort(container.begin(), container.end());
}

template <typename Container>
inline void reverseContainer(Container& container) {
  reverse(container.begin(), container.end());
}

template <typename T>
inline void withIdConstruction(vector<pair<T, T>>& with_id,
                               const vector<T>& arr) {
  for (int idx = 0; idx < arr.size(); ++idx) {
    with_id.push_back({arr[idx], idx});
  }
}
