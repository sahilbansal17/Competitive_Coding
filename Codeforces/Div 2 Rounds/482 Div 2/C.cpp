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

#define MAX 300010
vi graph[MAX];
int discovery[MAX];
int finish[MAX];
bool visited[MAX];
int record = 0; // timer

void dfs(int s){
    record ++;
    visited[s] = true;
    discovery[s] = record;
    rep(i, graph[s].size()){
        int next = graph[s][i];
        if(!visited[next]){
            dfs(next);
        }
    }
    record ++;
    finish[s] = record;
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
    freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
    #endif

    int n, x, y, F, B;
    ll res ;

    cin >> n >> F >> B;

    rep(i, n - 1){
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    // res = n*(n - 1) - (sz[F])*(sz[B] - sz[z]) where z is the child of B on SP from F to B
    // sz[x] represents size of subtree of x including x

    // consider B as root of the tree for calculation of subtree-sizes
    // call dfs on B to record discovery and finish times of vertices
    dfs(B);

    /*
    fl(i, 1, n){
        cout << discovery[i] << " " << finish[i] << "\n";
    }
    */

    int subTreeF, subTreeB, subTreeZ, z;

    subTreeB = n; // since it is the root
    subTreeF = 1 + (finish[F] - discovery[F] - 1)/2;

    // this is because every vertex in subtree takes effectively 2 units of time
    // and since exploringTime of subtree = ((finish[f] - 1) - discovery[f]) [1 subtracted because it takes 1 unit more to reach from subtree to the vertex]
    // thus subtreeSize = exploringTime/2

    // first need to find the child z of B that is on shortest path from F to B
    rep(i, graph[B].size()){
        // consider all children
        int child = graph[B][i];
        if(child == F){
            z = F;
            subTreeZ = subTreeF;
        }
        else{
            if(discovery[child] < discovery[F] && finish[F] < finish[child]){
                // if F is a descendant of child
                z = child;
                subTreeZ = 1 + (finish[z] - discovery[z] - 1)/2;
            }
        }
    }

    res = 1LL*n*(n - 1) - 1LL*subTreeF*(subTreeB - subTreeZ);
    cout << res;
	return 0;
}