int countingValleys(int n, string s) {
  int cur = 0;
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'U') {
      ++cur;
      if (cur == 0) {
        ++res;
      }
    } else {
      --cur;
    }
  }
  return res;
}
