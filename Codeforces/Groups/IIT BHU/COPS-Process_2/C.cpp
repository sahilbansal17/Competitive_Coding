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
#define MAX 1001

vi graph[MAX];
int choco[MAX];
bool visited[MAX];

bool dfs(int s, int prev){
    if(choco[s] < prev){
        // cout << "returned false from " << s << "\n";
        return false;
    }
    visited[s] = true;
    bool res = true;
    rep(i, graph[s].size()){
        int node = graph[s][i];
        if(!visited[node]){
            // cout << "from " << s << " to " << node << "\n";  
            res = res && dfs(node, choco[s]); 
        }
    }
    /*
    if(res)
        cout << "returned true from " << s << "\n";
    else
        cout << "returned false from " << s << "\n";
    */
    return res;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n, c, x, y;

    cin >> n >> c;

    rep(i, n - 1){
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    fl(i, 1, n + 1){
        cin >> choco[i];
        visited[i] = false;
    }
    if(dfs(c, -1)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
	return 0;
}