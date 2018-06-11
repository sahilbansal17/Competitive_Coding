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

vector <ull> adj[101]; //adjacency list
vi ts;	//topological sort 
bool vis[101];

// function to perform topological sort, similar to dfs function 
void topologicalSort(int u){
	vis[u] = 1;
	rep(i, adj[u].size()){
		if(vis[adj[u][i]] == 0){
			topologicalSort(adj[u][i]);
		}
	}
	ts.pb(u);
	return ;
} 

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n;
	cin >> n;

	vector <ull> a;
	ull val;

	rep(i, n){
		cin >> val;
		a.pb(val);
	}

	rep(i, n){
		fl(j, i+1, n){
			if(a[i] == 2*a[j]){
				adj[j].pb(i);
			}
			else if(a[j] == 2*a[i]){
				adj[i].pb(j);
			}
			else if(a[i] % 3 == 0 && a[j] == a[i] / 3){
				adj[i].pb(j);
			}
			else if(a[j] % 3 == 0 && a[i] == a[j] / 3){
				adj[j].pb(i);
			}
		}
	}

	// perform topological sort
	rep(i, n){
		if(vis[i] == 0){
			topologicalSort(i);
		}
	}

	// reverse the ts array to make it in right order
	reverse(ts.begin(),ts.end());

	/*
	rep(i, n){
		cout << a[i] << " ---> ";
		rep(j, adj[i].size()){
			cout << a[adj[i][j]] << " ";
		}
		cout << "\n";
	}
	*/
	rep(i, ts.size()){
		cout << a[ts[i]] << " ";
	}

	return 0;
}