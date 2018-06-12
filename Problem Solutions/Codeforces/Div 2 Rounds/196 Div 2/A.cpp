#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m, arr[100]={0};
	cin>>n>>m;

	for (int i = 0; i < m; ++i)
	{
		cin>>arr[i];
	}

	int result = INT_MAX;

	sort(arr, arr+m);

	for(int i=0;i<=m-n;i++)
	{
		result = min(result, arr[i+n-1]-arr[i]);
	}

	cout<<result<<endl;
	return 0;
}
