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
	#define MAX 5010

vector <int> graph[MAX];
	
bool good[MAX];

void dfs(int source){
	good[source] = true;
	rep(i, graph[source].size()){
		int adjacent = graph[source][i];
		if(!good[adjacent]){
			dfs(adjacent);
		}
	}
}

vector < pii > count_bad_vertices;

bool visited_bad[MAX];

int dfs1(int bad_vertex){
	int total_bad_reachable = 0;

	visited_bad[bad_vertex] = true;
	rep(i, graph[bad_vertex].size()){
		int adjacent = graph[bad_vertex][i];
		if(!good[adjacent] && !visited_bad[adjacent]){
			total_bad_reachable += 1 + dfs1(adjacent);
		}
	}

	return total_bad_reachable;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int num_vertices, num_edges, source, edge_start, edge_end;

	cin >> num_vertices >> num_edges >> source;

	rep(edge, num_edges){
		cin >> edge_start >> edge_end;
		graph[edge_start].push_back(edge_end);
	}

	/* Step 1: Mark all vertices reachable from source as good */
	dfs(source);

	/*/ 
	fl(i, 1, num_vertices + 1){
		if(good[i]){
			cout << i << " ";
		}
	}
	//*/

	/* Step 2: Call DFS on all bad vertices and count the number of other bad vertices
	   reachable from them. Store in a "vector of pair(count, index)" and then sort this 
	   in non-increasing order, so that vertices which can reach more bad vertices would
	   be preferred to have an additional egde connecting them from source.
	*/

	fl(i, 1, num_vertices + 1){
		if(!good[i]){
			// cout << "Bad vertices reachable from " << i << ": " << dfs1(i) << "\n";
			int reachable = dfs1(i);

			count_bad_vertices.pb(mp(reachable, i));

			/* clear the visited array for other bad vertices */
			fl(i, 1, num_vertices + 1){
				visited_bad[i] = false;
			}
		}
	}

	srt(count_bad_vertices);
	reverse(count_bad_vertices.begin(), count_bad_vertices.end());

	/* Step 3: Now, traverse the count pair vector from beginning in the order
	   of decreasing bad_reachable_vertices.
	   If the bad_vertex is still not good, then increase the answer by 1, 
	   and mark all other bad_reachable_vertices from it as good by using DFS
	*/

	int answer = 0;
	rep(i, count_bad_vertices.size()){
		int bad_vertex = count_bad_vertices[i].S;
		if(!good[bad_vertex]){
			answer += 1;
			dfs(bad_vertex);
		}
	}

	cout << answer;
	
	return 0;
}