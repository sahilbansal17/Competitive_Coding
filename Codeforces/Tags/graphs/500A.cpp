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

vi graph[30010]; // adjacency list
bool visited[30010];

void dfs(int s){
	visited[s] = true;
	rep(i, graph[s].size()){
		if(!visited[graph[s][i]]){
			dfs(graph[s][i]);
		}
	}
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n, t, a;

	cin >> n >> t;

	rep(i, n - 1){
		cin >> a;
		graph[a + i + 1].pb(i + 1); // from i+1 we can go to a+i+1
	}

	dfs(t);

	if(visited[1]){
		cout << "YES"; // can traverse following parent pointers from t to 1
	}
	else{
		cout << "NO";
	}

	return 0;
}