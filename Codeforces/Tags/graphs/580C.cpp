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
#define printTwo(a, b) cout << a << " " << b << "\n";
#define MAX 100010

bool cat[MAX];
vi graph[MAX];
bool visited[MAX];

int dfsRootToLeavesWithAtmostM_ConseCats(int s, int consec, int m){
	visited[s] = true;
	if(cat[s]){
		consec ++;
	}
	else{
		consec = 0;
	}
	if(consec > m){
		return 0;
	}
	int totalPaths = 0;
	bool leaf = true;
	rep(i, graph[s].size()){
		int next = graph[s][i];
		if(!visited[next]){
			leaf = false; // since has further children to be visited
			totalPaths += dfsRootToLeavesWithAtmostM_ConseCats(next, consec, m);
		}
	}
	if(leaf){
		return 1;
	}
	return totalPaths;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n, m, x, y;

	cin >> n >> m;

	fl(i, 1, n + 1){
		cin >> cat[i];
		visited[i] = false;
	}

	rep(i, n - 1){
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}

	cout << dfsRootToLeavesWithAtmostM_ConseCats(1, 0, m); 
	return 0;
}