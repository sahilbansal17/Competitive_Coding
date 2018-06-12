#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
const int L=1e5+7;
std::vector<int> v[L];
std::vector<int> type[102];
int dist[L][102];
void bfs(int cur)
{
	queue <int> q;
	int head;
	// cities which produce the current type of good are pushed into queue
	trace(type[cur],x)
	{
		dist[x][cur]=0;
		q.push(x);
	}
	// standard multisource bfs to assign shortest dist to each node
	while(sz(q))
	{
		head=q.front();
		q.pop();
		trace(v[head],x)
		{
			//if shortest distance of city x is not already assigned then assign it
			if(dist[x][cur]==-1)
			{
				dist[x][cur]=dist[head][cur]+1;
				q.push(x);
			}
		}
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int n,m,k,s,a,b,ans=0;
		cin>>n>>m>>k>>s;
		FOR(i,1,n+1)
		{
			cin>>a;
			type[a].pb(i); 		//type[i] contains the cities that produce ith good 
		}
		// initialising the dist array
		FOR(i,0,100001)FOR(j,0,101)dist[i][j]=-1;
		while(m--)
		{
			cin>>a>>b;
			v[a].pb(b);
			v[b].pb(a);
		}
		// performing multisource bfs for each good to find the mincost to bring that good to each city
		FOR(i,1,k+1)
			bfs(i);	
		FOR(i,1,n+1)
		{
			ans=0;
			// sorting the dist array to find the minimum cost
			sort(dist[i],dist[i]+k+1);
			//first s elements correspond to the optimal answer
			FOR(j,1,s+1)
				ans+=dist[i][j];
			cout<<ans<<" ";
		}	
		return 0;
}