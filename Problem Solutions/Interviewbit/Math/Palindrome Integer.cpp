int Solution::isPalindrome(int A) {
  if (A < 0) {
    return 0;
  }
  int reverse = 0;
  int copyOfA = A;
  while (A) {
    int rem = A % 10;
    reverse *= 10;
    reverse += rem;
    A /= 10;
  }
  if (reverse == copyOfA) {
    return 1;
  }
  return 0;
}