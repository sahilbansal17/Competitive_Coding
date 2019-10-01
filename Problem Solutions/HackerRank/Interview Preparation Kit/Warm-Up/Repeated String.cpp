typedef long ll;
long repeatedString(string s, long n) {
  int len = s.length();
  vector<ll> cnt(len + 1, 0);
  if (s[0] == 'a') {
    ++cnt[0];
  }
  for (int i = 1; i < len; ++i) {
    if (s[i] == 'a') {
      cnt[i] = cnt[i - 1] + 1;
    } else {
      cnt[i] = cnt[i - 1];
    }
  }
  if (n <= 1ll * len) {
    return cnt[n - 1];
  }

  ll blocks = n / len;
  ll res = blocks * cnt[len - 1];

  int rem = n % len;
  if (rem != 0) {
    res += cnt[rem - 1];
  }

  return res;
}