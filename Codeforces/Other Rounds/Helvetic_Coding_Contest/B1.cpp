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

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int N, val1, val2;

	cin >> N;

	vi adjList[N+1];
	rep(i, N-1){
		cin >> val1 >> val2;
		adjList[val1].pb(val2);
		adjList[val2].pb(val1);
	}

	int remoteCount = 0; 
	// find those planets which have only a single incident egde, i.e. 
	// size of adjList is 1 for that planet 
	fl(i,1, N+1){
		if(adjList[i].size() == 1){
			remoteCount ++;
		}
	}

	cout << remoteCount;

	return 0;
}