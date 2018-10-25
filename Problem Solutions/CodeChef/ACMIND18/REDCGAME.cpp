#include<bits/stdc++.h>
using namespace std;
#define fl(i,a,n) for(int i=a;i<(n);++i)
#define rfl(i,a,n) for(int i=(n-1);i>a-1;i--)
#define rep(i,n) for(int i=1;i<=n;i++)
#define rrep(i,n) for(int i=n;i>0;i--)
#define srt(a,n) sort(a+1,a+n+1)
#define li long
#define ll long long
#define ull unsigned long long
#define clr(a) memset(a,0,sizeof(a))
#define vi vector <int>
#define vll vector <long long>
#define pii pair <int,int>
#define mod 1000000007
#define pb push_back
#define fr first
#define sc second
#define loop(i,n) for(int i=0;i<n;i++)
#define pi 3.1415926535

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[51];
		rep(i,n)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		if(n==1)
		{
			cout<<a[n]<<endl;
		}
		else if(n==2)
		{
			if(a[1]<=k)
			{
				cout<<a[1]+a[2]<<endl;
			}
			else cout<<2*k + a[2] - a[1]<<endl;
		}
		else
		{
			int j = 1,sum = 0;
			while(a[j]<=k&&j<n+1)
			{
				j++;
			}
			//cout<<j<<endl;
			if(j==n+1||j==n)
			{
				rep(i,n)
				{
					sum+=a[i];
				}
				cout<<sum<<endl;
			}
			else if(j==n-1)
			{
				rep(i,j-1)
				{
					sum+=a[i];
				}
				cout<<sum + 2*k + a[n] - a[n-1]<<endl;
			}
			else
			{
				for(int i=1;i<j;i++)
				{
					sum+=a[i];
					//cout<<"j "<<a[i]<<endl;
				}
				//cout<<sum<<endl;
				int d1 = 0,d2 = a[n-1] - k;
				for(int i=j;i<n-1;i++)
				{
					d1+=(a[i] - k);
				}
				sum += (n-j)*k;
				//cout<<d1<<" "<<d2<<" "<<sum<<endl;
				if(d2>d1)
				{
					d2 = d2 - d1;
					sum = sum + a[n] - d2;
				}
				else
				{
					if((d2+d1)&1)
					{
						sum = sum + a[n] - 1;
					}
					else
					{
						sum = sum + a[n];
					}
				}
				cout<<sum<<endl;
			}
		}
	}
	return 0;
}