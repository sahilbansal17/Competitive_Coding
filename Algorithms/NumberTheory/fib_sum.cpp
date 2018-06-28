#include <bits/stdc++.h>
using namespace std;
#define ll long long //ll would be used throughout the code to refer to long long
#define MOD 1000000007
void multiply( ll a[2][2], ll b[2][2] ) // Function is supposed to perform multiplication of the a matrices a and b
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
 /* Concept used to optimize the calcluation of the power:
    pow(a,n) = pow(a,n/2)*pow(a,n/2) if n is even
    pow(a,n) = pow(a,(n-1)/2*pow(a,(n-1)/2)*a if n is odd
    This allows us to reduce the time complexity to O(log n)*/
/* Time complexity proof:
 T(n) = T(n/2) + 1 It takes unit time for multiplication
now note that 1 == pow(n,log 1)
therefore by master theorem your time complexity is O(log n)
*/
void power( ll a[2][2], ll n ) // recursively multiplies the matrix to give the matrix a[2][2]^n
{
  if( n == 0 || n == 1)
      return;
  ll b[2][2] = {{1,1},{1,0}};//creating a 2d array/matrix b
 
  power(a, n/2);
  multiply(a, a); //exponentiation
//  
  if ( n%2 != 0 )
     multiply(a, b);
}
 //fibonacci_matrix equation relation -> pow({{1,1},{1,0}},n) =={{F(n+1),F(n)},{F(n),F(n-1)}} where F(n) is the nth fibonacci number
ll fib( ll n ) // used to find the value of nth finbonacci number
{
  ll a[2][2] = {{1,1},{1,0}};
  if (n == 0)
    return 0;
  power(a, n-1);
  return a[0][0];//(as from fibonacci matrix equation a[0][0] == F((n-1)+1))
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