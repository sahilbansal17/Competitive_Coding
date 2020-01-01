/*Solution to a problem from Southern and Volga Russia Qualifier 2019-2020 in codeforces, using dfs*/


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
const int maxN = 2e5+5; // CAMBIAR ESTE

// GJNM
int v, cv;
vi g[maxN];
bool c[maxN];
bool vis[maxN];
int k[maxN];
map<int,bool> ans;
int x;

void dfs( int a )
{
	vis[a] = true;
	k[a] = 0;
	int cont = 0;
	for ( int b : g[a] )
	{
		if ( !vis[b] )
		{
			dfs(b);
			if ( k[b] || c[b]) k[a] ++;
			cont++;
		}
	}
	if ( cont == k[a] && !c[a]) ans[a] = true;
}

int main()
{
	rii(v,cv);
	FOR(i,0,cv)
	{
		int aux; ri(aux);
		c[aux] = true;
		x = aux;
	}
	FOR(i,0,v)
	{
		int a,b;
		rii(a,b);
		g[a].pb(b);
		g[b].pb(a);

	}
	dfs(x);
	printf("%d\n",(int)ans.size() );
	for ( auto p : ans )
	{
		if ( c[p.first] ) continue;
		printf("%d ", p.first );
	}
	printf("\n");
	
	return 0;
}