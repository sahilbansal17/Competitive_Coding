/*Solution to a problem from Southern and Volga Russia Qualifier 2019-2020 in codeforces, using greedy*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 1e5; // CAMBIAR ESTE

// GJNM

int main()
{
	int n; ri(n);
	printf("%d\n", 3*n*n/4);
	for( int i = 1 ; i <= n ; i += 2 )
	{
		for( int j = 1 ; j <= n ; j++ )
		{
			if ( j&1 )
			{
				printf("1 %d %d 2\n", i, j+1);
				printf("1 %d %d 2\n", i+1, j);				
			}
			else
			{
				printf("2 %d %d 1\n", i,j-1);
			}
		}
		
	}
	return 0;
}