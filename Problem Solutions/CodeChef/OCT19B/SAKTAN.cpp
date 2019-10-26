#include<bits/stdc++.h>
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
ll n,m,q; 
cin>>n>>m>>q; 		
ll l[n];
ll tp[m];
memset(l,0,sizeof(l));	
memset(tp,0,sizeof(tp));
ll x,y;	
while(q-->0)
{ 			
cin>>x>>y;			
x--,
y--; 			
l[x] = (l[x]+1)%2;			
tp[y] = (tp[y]+1)%2;		
} 		
ll c=0,s=0; 		
for(ll j=0;j<m;j++)
{			
if(tp[j]==1)				
s++;						
} 		
loop(n)
{			
if(l[i]==0)
{				
c= c+s;			
}
else
{	
c= c+(m-s);			
}		
}
	cout<<c<<endl;
}
 	return 0;
}