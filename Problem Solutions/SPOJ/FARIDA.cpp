/******************************************
* AUTHOR : AAYUSH GARG*
* NICK : aayushgarg_03 *
* INSTITUTION : BIT MESRA *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 1000000007
#define dd double
#define ld long double
#define for0(i, n) for(ll i = 0; i < n; i++)
#define for2(a,b,c) for(ll i=a;i<b;i+=c)
#define for1(i,n) for(ll i=1;i<=n;i++)
#define vec vector<ll>
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define VP vector< pii >
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define ascii(c) (int)char (c)
#define all(v) (v).begin(),(v).end()
#define Sort(v) sort(v.begin(), v.end(), sortbysec)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define N 1000000


int main() 
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);

ll t;
cin>>t;

for0(i,t)
{
	ll n;
	cin>>n;
	ll a[n];
	for0(i,n)
	 cin>>a[i];

	ll b[n];
	b[0] = a[0];
	b[1] = max(a[0],a[1]);
	for(ll i=2;i<n;i++)
	{
		b[i] = max(a[i]+b[i-2],b[i-1]);
	}
	if(n==0)
		cout<<"Case"<<" "<<i+1<<":"<<" "<<0<<endl;
	else
	    cout<<"Case"<<" "<<i+1<<":"<<" "<<b[n-1]<<endl;
}

return 0;
}
