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

template <typename Container>
//Finding the frequency of an element in an array (change the data type as needed)
inline int frequency(Container& container,int ele) {
  return count(container.begin(), container.end(),ele);
}

template <typename T>
//for making a list of value and index pairs from a list
inline void withIdConstruction(vector<pair<T, T>>& with_id,
                               const vector<int>& arr) {
  for (int idx = 0; idx < arr.size(); ++idx) {
    with_id.push_back({arr[idx], idx});
  }
}
