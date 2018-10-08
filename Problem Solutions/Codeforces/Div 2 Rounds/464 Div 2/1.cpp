#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int main()
{
	int t,i,j,n;
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++)
	{cin>>arr[i];
	arr[i]--;
	}
	for(i=0;i<n;i++)
	{
		int g=i;
		for(j=0;j<3;j++)
		{
			g=arr[g];
		}
		if(g==i)
		break;
	}
	
	if(i==n)
	cout<<"NO";
	else
	cout<<"YES";
}

