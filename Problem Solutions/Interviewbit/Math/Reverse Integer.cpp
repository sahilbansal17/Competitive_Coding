typedef long long ll;
int Solution::reverse(int A) {
  bool neg = 0;
  if (A < 0) {
    neg = 1;
    A *= -1;
  }
  ll reverse = 0;
  while (A) {
    ll rem = A % 10;
    reverse *= 10;
    reverse += rem;
    A /= 10;
  }
  if (reverse > 1ll * INT_MAX) {
    return 0;
  }
  if (neg) {
    reverse *= -1;
  }
  return reverse;
}