#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int main()
{
	int t,i,j,n;
	cin>>n;
	ll arr[2*n],s,f;
	for(i=0;i<n;i++)
	{cin>>arr[i];
		arr[n+i]=arr[i];
	}
	cin>>s>>f;
	int p=f-s;
	long long maxx=0,maxi;
	for(i=0;i<p;i++)
	maxx+=arr[i];
	maxi=0;
	ll sum=maxx;
	ll ans=99999999;
	ans=s;
	for(i;i<(n+p-1);i++)
	{
		sum+=arr[i];
		sum-=arr[i-p];
		if(sum>maxx)
		{
			maxx=sum;
			maxi=i-p+1;
			
			ans=s+n-maxi;
			if(ans>=(n+1))
			ans-=n;
		}
		else if(sum==maxx)
		{
			maxi=i-p+1;
			if(s+n-maxi>=(n+1))
			{
				if(s+n-maxi-n<ans)
				{
					ans=s+n-maxi;
					if(ans>=(n+1))
					ans-=n;
				}	
			}
			else
			{
				if(s+n-maxi<ans)
					ans=s+n-maxi;
			}
			
		}
	}
	cout<<ans;
}

