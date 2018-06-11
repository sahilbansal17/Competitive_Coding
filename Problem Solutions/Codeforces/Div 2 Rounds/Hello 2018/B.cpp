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

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int n,x;

	cin >> n;

	vi v(1001,0);

	vi adj[1001];
	rep(i,n-1){
		cin >> x;
		v[x] = 1; // x is a non-leaf
		adj[x].pb(i+2) ; // x has i+2 as child 
	}
	int flag = 1;
	fl(i,1,n+1){
		if(v[i] == 1){
			int count = 0;
			fl(j,0,adj[i].size()){
				if(v[adj[i][j]] == 0){
					count ++ ;
				}
			}
			if(count < 3){
				flag = 0;
				break;
			}
		}
	}
	if(flag == 1){
		cout << "Yes";
	}
	else{
		cout << "No";
	}
	return 0;
}