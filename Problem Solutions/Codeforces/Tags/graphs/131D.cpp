#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)
#define rfl(i,a,b) for(int i(a);i>=(b);i--)
#define srt(v) sort((v).begin(),(v).end())
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define slen(s) s.length()
#define F first
#define S second
#define MAX 3010

vi graph[MAX];
bool visited[MAX];
int parent[MAX];
int dist[MAX];
int cycleVert, cycleVertEnd;

void dfs(int s){
	visited[s] = true;
	rep(i, graph[s].size()){
		int next = graph[s][i];
		if(!visited[next]){
			parent[next] = s;
			dfs(next);
		}
		else if(next != parent[s] && next != cycleVert){
			// this is an ancestor (back edge) in undirected graph
			// => cycle
			
			// this vertex is returned as last vertex of cycle
			// traverse its parent until you get 0 to get the 1st vertex of cycle

			cycleVert = s;

			// the second condition next != cycleVert makes sure we don't consider the cycle edge in reverse direction
		}
		else if(next == cycleVert){
			// cycle edge in reverse direction gives end of cycle vertex
			cycleVertEnd = s;
		}
	}
}

void bfsShortestDistanceToAll(int s){
	queue <int> q;
	q.push(s);
	// dist[s] = 0; // already set earlier since cycleVert
	while(!q.empty()){
		int node = q.front();
		q.pop();
		int sz = graph[node].size();
		rep(i, sz){
			int next = graph[node][i];
			if(dist[next] > dist[node] + 1){
				dist[next] = dist[node] + 1;
				q.push(next); 
			}
			else if(dist[next] == 0 && !visited[next]){
				// one cycle vertex to another cycle vertex
				q.push(next);
				visited[next] = true;
			}
		}
	}

}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n, x, y;

	cin >> n;

	rep(i, n){
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	
	// initialize distance to MAX possible
	rep(i, n + 1){
		dist[i] = MAX;
	}

	dfs(1);

	/*
	cout << "Cycle Start:" << cycleVert << " Cycle End:" << cycleVertEnd << "\n";
	fl(i, 1, n + 1){
		cout << parent[i] << " ";
	}
	cout << "\n";
	*/

	dist[cycleVert] = 0;
	int current = cycleVert; // copy of cycleVert
	// mark all the vertices in the cycle at distance 0
	while(parent[current] != cycleVertEnd){
		current = parent[current];
		visited[current] = false;
		dist[current] = 0;
	}
	dist[cycleVertEnd] = 0;
	visited[cycleVertEnd] = false;

	// calculate distances to all vertices not in cycle using bfs

	bfsShortestDistanceToAll(cycleVert);

	fl(i, 1, n + 1){
		cout << dist[i] << " ";
	}
	return 0;
}