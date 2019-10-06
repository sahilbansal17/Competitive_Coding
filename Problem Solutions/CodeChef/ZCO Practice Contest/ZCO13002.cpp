#include <bits/stdc++.h>

using namespace std;

int n, m, k;
bool safe[505][505];
int dp[505][505], val[505][505];

int main()
{
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> val[i][j];
			dp[i][j] = INT_MIN;
			safe[i][j] = 0;
		}
	}

	for(int i = 0; i < m; i++)
	{
		int r, c, size;
		cin >> r >> c >> size;
		
		for(int j = -1*size; j<=size; j++)
		{
			for(int k = -1*(size - abs(j)); k<=size - abs(j); k++)
			{
				if((r+j)>=1 && (r+j)<=n && (c+k)>=1 && (c+k)<=n)
					safe[r+j][c+k] = 1;
			}
		}
	}

	dp[1][1] = val[1][1];
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(!safe[i][j] || dp[i][j] == INT_MIN) continue;
			
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + val[i + 1][j]);
			dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + val[i][j + 1]);
		}
	}

	if(dp[n][n] == INT_MIN) cout << "NO";
	else cout << "YES\n" << dp[n][n];
}
