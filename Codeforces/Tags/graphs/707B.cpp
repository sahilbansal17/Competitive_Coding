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
#define MAX 100010
typedef vector < pii > vpii;

vpii graph[MAX]; // weighted graph, first of pair: weight, second of pair: vertex
vi storages;

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n, m, k, w, x, y, shortestPath = 1000000001, storage, length, vertex;

	cin >> n >> m >> k;

	rep(i, m){
		cin >> x >> y >> w;
		graph[x].pb(mp(w, y));
		graph[y].pb(mp(w, x));
	}
	
	if(k == 0){
		shortestPath = -1;
	}
	else{
		rep(i, k){
			cin >> storage;
			storages.pb(storage);
		}
		srt(storages); // so that binary search can be used to check whether a vertex is storage
		rep(i, storages.size()){
			storage = storages[i];
			srt(graph[storage]); // increasing order of weights
			rep(j, graph[storage].size()){
				length = graph[storage][j].F;
				vertex = graph[storage][j].S;
				// cout << length << " " << vertex << "\n";
				if(shortestPath < length){
					break;
				}
				// if vertex not a storage, storage -> city connection
				if(!binary_search(storages.begin(), storages.end(), vertex)){
					if(length < shortestPath){
						shortestPath = length;
						break;
					}
				}
			}
		}
	}
	if(shortestPath == 1000000001){
		cout << "-1";
	}
	else{
		cout << shortestPath;
	}
	return 0;
}