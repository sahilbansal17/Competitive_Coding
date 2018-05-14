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

	int n,m ;

	cin >> n >> m; // n : no of strings, m : length of each string 

	vector <string> vs;
	string str;

	rep(i, n){
		cin >> str;
		vs.pb(str);
	}

	// for each position (index) of all strings, find distinct no of characters

	ll res = 1;
	rep(i, m){
		vi hashTable(26, 0);
		int count = 0; // for a particular location of all strings 
		rep(j, n){
			if(hashTable[vs[j][i] - 65] == 0){
				count ++;
				hashTable[vs[j][i] - 65] ++;
			}
		}
		res = (1LL * res * count) % MOD; 
	}

	cout << res; 
	return 0;
}