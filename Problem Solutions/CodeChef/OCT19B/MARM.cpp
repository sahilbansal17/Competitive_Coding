#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long int 
#define ld long double
#define fi first
#define se second
#define mod 1000000007
#define test long long int t; cin>>t; while(t-->0)
#define fIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define loop(n) for(long long int i=0;i<n;i++)
using namespace std;
ll gcd(ll a, ll b)
{ 

if (b == 0) 

return a; 

return gcd(b, a % b);

}

ll lcm(ll a, ll b) 

{ 

return (a*b)/__gcd(a, b); 

}

ll power(ll x, unsigned ll y) 

{ 

ll temp; 

if( y == 0) 

return 1; 

temp = power(x, y/2); 

if (y%2 == 0) 

return temp*temp; 

else

return x*temp*temp; 

}

bool isPrime(ll num)

{

bool flag=true;

for(ll i =2;i<=num/2;i++) 

{

if(num%i==0) 

{

flag=false;

break;

}

}

return flag;

}

bool isPalin(ll num)

{

bool flag=false;

ll digit,rev=0,n=num;

do

{

digit = num % 10;

rev = (rev * 10) + digit;

num = num / 10;

} while (num != 0);

if(rev==n)

flag=true;

return flag;

}

ll sumofdigits(ll n)

{

ll c=0;

while(n>0)

{

c++;

n/=10;

}

return c;
    }
int main()
{
    fIO
    test
    {
        ll n,k,d=0;
        cin>>n>>k;
        ll p[n];
        loop(n)
        {
            cin>>p[i];
        }
        if(k>(3*n))
        {
            if(n%2!=0)
            {
            p[n/2]=0;
                k=k%(3*n);
        }
            else
            {
                k=k%(3*n);
        }
    }
        for(ll i=0;i<k;i++)
        {
           	ll a = p[i%n];	
            	ll b = p[n-(i%n)-1];		
            p[i%n] = a^b; 
    }
        for(ll i=0;i<n;i++)
        {
        cout<<p[i]<<" ";
    }
        cout<<endl;
}
    return 0;
    }