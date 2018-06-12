#include <bits/stdc++.h>

using namespace std;

/* Template file for Online Algorithmic Competitions */
/* Typedefs */
	/* Basic types */
	typedef long long ll;
	typedef unsigned long long ull;
	/* STL containers */
	typedef vector <int> vi;
	typedef vector <ll> vll;
	typedef pair <int,int> pii;
	typedef pair <ll,ll> pll;
	typedef vector < pii > vpii;
	typedef vector < pll > vpll;
/* Macros */
	/* Loops */
	#define fl(i,a,b) for(int i(a);i<(b);i++)
	#define rep(i,n) fl(i,0,n)
	#define rep1(i,n) fl(i,1,n)
	#define rfl(i,a,b) for(int i(a);i>=(b);i--)
	/* Algorithmic functions */
	#define srt(v) sort((v).begin(),(v).end())
	/* STL container methods */
	#define pb push_back
	#define mp make_pair
	/* String methods */
	#define slen(s) s.length()
	/* Shorthand notations */
	#define F first
	#define S second
	#define MOD 1000000007
	#define MAX 1005

int adj[MAX][MAX];

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif
	
	int n, a, b;

	cin >> n >> a >> b;

	if(a != 1 && b != 1){
		cout << "NO";
		return 0;
	}
	if(a == 1 && b == 1){
		if(n == 1){
			cout << "YES\n";
			cout << "0";
		}
		else if(n == 2 || n == 3){
			cout << "NO";
		}
		else{
			// n > 3
			fl(i, 2, n){
				adj[1][i] = 1;
				adj[i][1] = 1;
			}
			adj[2][n] = 1;
			adj[n][2] = 1;
			cout << "YES\n";
			fl(i, 1, n + 1){
				fl(j, 1, n + 1){
					cout << adj[i][j];
				}
				cout << "\n";
			}
		}
	}
	else if(a == 1){

		cout << "YES\n";

		int largest = n - b + 1;

		fl(i, 2, largest + 1){
			adj[1][i] = 1;
			adj[i][1] = 1;
		}

		fl(i, 1, n + 1){
			fl(j, 1, n + 1){
				if(adj[i][j] == 1 || i == j){
					cout << "0";
				}	
				else{
					cout << "1";
				}
			}
			cout << "\n";
		}
	}
	else if(b == 1){

		cout << "YES\n";

		int largest = n - a + 1;

		fl(i, 2, largest + 1){
			adj[1][i] = 1;
			adj[i][1] = 1;
		}

		fl(i, 1, n + 1){
			fl(j, 1, n + 1){
				cout << adj[i][j];
			}
			cout << "\n";
		}
	}


	return 0;
}