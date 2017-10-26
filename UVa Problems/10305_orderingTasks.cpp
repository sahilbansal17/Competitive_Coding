// 10305 - Ordering Tasks, based on Topological sort
// link to question : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=668&page=show_problem&problem=1246
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
// mostly used libraries including common STL libraries 
using namespace std;

// list of shortcuts to improve the readability of code 
typedef vector <int> vi;
typedef pair <int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i,a,b) for(int i(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define pb push_back


vi adj[101]; //adjacency list
vi ts;	//topological sort 
bool vis[101];

// function to perform topological sort, similar to dfs function 
void topologicalSort(int u){
	vis[u] = 1;
	FOR(i,0,adj[u].size()){
		if(vis[adj[u][i]] == 0){
			topologicalSort(adj[u][i]);
		}
	}
	ts.pb(u);
	return ;
} 

//function to print the adjacency list just for checking purpose
void printAdj(int n){
	FOR(i,1,n){
		cout << i << ":";
		FOR(j,0,adj[i].size()){
			cout << adj[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main(){

	
	/*
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	*/
	
	int n,m,i,j; //course i must be taken before course j
	cin >> n >> m;

	while(n+m != 0){ //both n AND m should not be zero i.e. (n OR m) should be greater than zero
		
		// clear the adjacency list
		FOR(k,0,m){
			adj[k].clear();
		}

		// create the adjacency list
		FOR(k,0,m){
			cin >> i >> j;
			adj[i].pb(j);
		}
		
		// set elements of visited array to false
		FOR(i,1,n+1){
			vis[i] = false;
		}

		// perform topological sort
		FOR(i,1,n+1){
			if(vis[i] == 0){
				topologicalSort(i);
			}
		}

		// reverse the ts array to make it in right order
		reverse(ts.begin(),ts.end());

		// print the elements of the ts array 
		FOR(i,0,n){
			if(i != n-1){
				cout << ts[i] << " "; //output formatting 
			}
			else{
				cout << ts[i]; //no space after the last element
			}
		}

		cout << "\n";
		cin >> n >> m;
	}

	return 0;
}