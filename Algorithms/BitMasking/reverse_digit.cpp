#include<iostream>
#include<cmath>
using namespace std;


long long Reverse(int x) {
  long long result = 0, x_remaining = abs(x);
  while (x_remaining) {
    result = result * 10 + x_remaining % 10;
    x_remaining /= 10;
  }
  return x < 0 ? -result : result;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  cout<<Reverse(n);
  return 0;
}
