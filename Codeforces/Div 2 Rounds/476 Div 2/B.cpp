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

ll mat[105][105];

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,m;

	cin >> n >> m;

	char a[105][105];

	rep(i, n){
		rep(j, n){
			cin >> a[i][j];
			mat[i][j] = 0;
		}
	}

	// horizontal deckers
	rep(i, n){
		rep(j, n-m+1){
			int flag = 1;
			fl(k, j, j+m){
				if(a[i][k] == '#'){
					flag = 0;
					break;
				}
			}
			if(flag == 1){
				fl(k, j, j+m){
					mat[i][k] ++;
				}
			}
		}
	}

	// vertical deckers 
	rep(i, n){
		rep(j, n-m+1){
			int flag = 1;
			fl(k, j, j+m){
				if(a[k][i] == '#'){
					flag = 0;
					break;
				}
			}
			if(flag == 1){
				fl(k, j, j+m){
					mat[k][i] ++;
				}
			}
		}
	}	

	int max_x = 0, max_y = 0;
	ll max_count = 0;

	rep(i, n){
		rep(j, n){
			// cout << mat[i][j] << " ";
			if(mat[i][j] > max_count){
				max_x = i;
				max_y = j;
				max_count = mat[i][j];
			}
		}
		// cout << "\n";
	}

	cout << max_x + 1 << " " << max_y + 1;
	return 0;
}