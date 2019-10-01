int sockMerchant(int n, vector<int> ar) {
  unordered_map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    ++cnt[ar[i]];
  }
  int res = 0;
  for (auto val : cnt) {
    res += (val.second) / 2;
  }
  return res;
}