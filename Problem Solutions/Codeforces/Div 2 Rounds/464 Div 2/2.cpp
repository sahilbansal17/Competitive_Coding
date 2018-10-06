#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int main()
{
	int t,i,j;
	ll n,k;
	cin>>n>>k;
	ll arr[k];
	for(i=0;i<k;i++)
		cin>>arr[i];
		
	long long maxx=0,maxi;
	for(i=0;i<k;i++)
	{
		if((n/arr[i])*arr[i]>maxx)
		{
			maxx=(n/arr[i])*arr[i];
			maxi=i+1;
		}
	}
	if(maxx==0)
	cout<<1<<" 0";
	else
	cout<<maxi<<" "<<n/arr[maxi-1];
}

