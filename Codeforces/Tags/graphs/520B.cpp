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

#define MAX 99999
vi graph[20001]; // adjacency list
// bool visited[30010];

int bfsShortestDistance(int s, int m){
	queue <int> q; // queue for pushing adjacent vertices to current level vertices
    
	// dist array maintains the SHORTEST DISTANCE to a vertex from source s
    int dist[20002];
    rep(i, 20002){
        dist[i] = MAX; // initialize to the value greater than max distance possible
    }

    // push the source vertex to the queue
    q.push(s);
    dist[s] = 0; // distance of source from source = 0
    
    // while there is an unvisited vertex
    while(!q.empty()){
    	// the node whose adjacency list would be traversed
        int node = q.front();
        q.pop(); // pop it from the queue since it need not be seen again
        int sz = graph[node].size(); // size of node's adjacency list
       	rep(i, sz){
            int next = graph[node][i]; // next node to be visited
            if(next >= 20000 || next < 1){
                continue; // no such vertex exists
            }
            // if not already visited (distance will be larger than shortest distance)
            if(dist[next] > dist[node] + 1){
                dist[next] = dist[node] + 1;
                q.push(next); // needs to be traverse in next loop iteration, i.e. next level
            }
        }
    }
    return dist[m]; // shortest distance from s to m

}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n, m;
    cin >> n >> m;
    
    rep(i, 20000){
        graph[i].pb(i*2);
        graph[i].pb(i - 1);
    }

    cout << bfsShortestDistance(n, m);

	return 0;
}