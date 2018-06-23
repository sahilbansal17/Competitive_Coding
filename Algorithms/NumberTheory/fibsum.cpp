#include <bits/stdc++.h>
using namespace std;
#define ll long long //ll would be used throughout the code to refer to long long
#define MOD 1000000007
void multiply( ll a[2][2], ll b[2][2] )
{
  ll x =  a[0][0] * b[0][0] + a[0][1] * b[1][0];
  ll y =  a[0][0] * b[0][1] + a[0][1] * b[1][1];
  ll z =  a[1][0] * b[0][0] + a[1][1] * b[1][0];
  ll w =  a[1][0] * b[0][1] + a[1][1] * b[1][1];
 
  a[0][0] = x;
  a[0][1] = y;
  a[1][0] = z;
  a[1][1] = w;
}
 
void power( ll a[2][2], ll n )
{
  if( n == 0 || n == 1)
      return;
  ll b[2][2] = {{1,1},{1,0}};//creating array b
 
  power(a, n/2);
  multiply(a, a); // modular exponentiation
 
  if ( n%2 != 0 )
     multiply(a, b);
}
 
ll fib( ll n )
{
  ll a[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(a, n-1);
  return a[0][0];
}
 
 int main()
{
  ll t;
  cin >> t ;
  while(t--)
  {
    ll l,r;
    cin>>l>>r;
    cout<<(fib(r+2) - fib(l+1) + MOD)%MOD<<endl;
  }
  return 0;
}