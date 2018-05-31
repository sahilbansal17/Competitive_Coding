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
#define MAX 2005

vi graph[2005]; // adjacency list
bool visited[2005];
int dist[2005]; // to compute shortest distances in bfs

// returns maximum distance of any vertex v from s
int bfsMaxDistance(int s){
	queue <int> q; // queue for pushing adjacent vertices to current level vertices
    
	int maxDist ; // refers to the height of the BFS Tree
    
    rep(i, 2005){
        dist[i] = MAX;
    }

    // push the source vertex to the queue
    q.push(s);
    visited[s] = true;
    dist[s] = 0;
    maxDist = 0; 
    
    // while there is an unvisited vertex
    while(!q.empty()){
    	// the node whose adjacency list would be traversed
        int node = q.front();
        q.pop(); // pop it from the queue since it need not be seen again
        int sz = graph[node].size(); // size of node's adjacency list
       	rep(i, sz){
            int next = graph[node][i]; // next node to be visited

            // if not already visited (distance will be larger than shortest distance)
            if(!visited[next]){
                visited[next] = true;
                dist[next] = dist[node] + 1;
                if(dist[next] > maxDist){
                    maxDist = dist[next];
                }
                q.push(next); // needs to be traverse in next loop iteration, i.e. next level
            }
        }
    }

    return maxDist; 
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n, imm;

    cin >> n;

    vi roots; // the possible tree roots
    fl(i, 1, n + 1){
        // immediate manager for the i-th employee
        cin >> imm;
        if(imm == -1){
            roots.pb(i); // i doesn't have any ancestor (immediate manager)
        }
        else{
            graph[i].pb(imm);
            graph[imm].pb(i);
        }
    }

    rep(i, 2001){
        visited[i] = false;
    }
    int minGroups = 0; // it will be the maximum height of any bfs tree among the bfs forest

    rep(i, roots.size()){
        int root = roots[i], height;
        if(!visited[root]){
            height = bfsMaxDistance(root);
            if(height + 1 > minGroups){
                minGroups = height + 1;
            }
        }
    }
    cout << minGroups;

	return 0;
}