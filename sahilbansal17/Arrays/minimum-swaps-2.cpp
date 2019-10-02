int minimumSwaps(vector<int> arr) {
  int n = arr.size();
  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] != i + 1) {
      ++count;
      for (int j = i + 1; j < n; ++j) {
        if (arr[j] == i + 1) {
          swap(arr[i], arr[j]);
          break;
        }
      }
    }
  }
  return count;
}