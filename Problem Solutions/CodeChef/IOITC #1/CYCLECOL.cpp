#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
	/* Basic types */
	typedef long long ll;
	typedef unsigned long long ull;
	/* STL containers */
	typedef vector <int> vi;
	typedef vector <ll> vll;
	typedef pair <int,int> pii;
	typedef pair <ll,ll> pll;
	typedef vector < pii > vpii;
	typedef vector < pll > vpll;
/* Macros */
	/* Loops */
	#define fl(i,a,b) for(int i(a);i<(b);i++)
	#define rep(i,n) fl(i,0,n)
	#define rfl(i,a,b) for(int i(a);i>=(b);i--)
	/* Algorithmic functions */
	#define srt(v) sort((v).begin(),(v).end())
	/* STL container methods */
	#define pb push_back
	#define mp make_pair
	/* String methods */
	#define slen(s) s.length()
	/* Shorthand notations */
	#define F first
	#define S second
	#define MOD 1000000007
	#define MAX 100010

vector <int> g[MAX];
int c[MAX];

int cycleVert, cycleVertEnd;
bool visited[MAX];
int parent[MAX];
bool new_visited[MAX];

void dfs(int s){
	visited[s] = true;
	rep(i, g[s].size()){
		int next = g[s][i];
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

void dfs_tree(int s){
	new_visited[s] = true;
	rep(i, g[s].size()){
		int next = g[s][i];
		if(!new_visited[next]){
			c[next] = 1 + (c[s] % 4);
			dfs_tree(next);
		}
	}
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int t;

	cin >> t;

	int n, m, x, y;

	rep(i, t){
		cin >> n >> m;

		/* assuming m = n, subtask 1 */
		rep(j, m){
			cin >> x >> y;
			g[x].pb(y);
			g[y].pb(x);
		}

		if(m == n){
			cout << "1\n";
			dfs(1);
			// cout << cycleVert << " " << cycleVertEnd;
			
			int current = cycleVert;
		
			int color = 1, cycle_length = 2;
			
			new_visited[current] = true;
			c[current] = color;
			
			while(parent[current] != cycleVertEnd){
				current = parent[current];
				new_visited[current] = true;
				c[current] = 1 + (color) % 4;
				color += 1;
				cycle_length += 1;
			}
			new_visited[cycleVertEnd] = true;
			
			if(cycle_length % 4 == 1){
				c[cycleVertEnd] = 2;
			}
			else{
				c[cycleVertEnd] = 1 + (color) % 4;
			}
			
			vi branching;
			fl(k, 1, m + 1){
				if(!new_visited[k]){
					rep(j, g[k].size()){
						if(new_visited[g[k][j]]){
							branching.pb(k);
						}
					}
				}
			}
			// cout << branching;
			// cout << g[branching].size();
			int index;
			rep(l, branching.size()){
				int branch = branching[l];
				rep(k, g[branch].size()){
					int next = g[branch][k];
					if(new_visited[next]){
						c[branch] = 1 + (c[next] % 4);
						index = k;
					}
				}
				g[branch].erase(g[branch].begin() + index);
				dfs_tree(branch);
			}

			fl(k, 1, m + 1){
				cout << c[k] << " ";
			}
		
			rep(j, n + 1){
				g[j].clear();
				parent[j] = -1;
				visited[j] = false;
				new_visited[j] = false;
			}
			branching.clear();
		}

		else{
			cout << ".";
		}
		cout << "\n";
	}



	return 0;
}