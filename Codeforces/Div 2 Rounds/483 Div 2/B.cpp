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

	int n, m;

	cin >> n >> m;

	char a[105][105];

	rep(i, n){
		rep(j, m){
			cin >> a[i][j];
			// cout << a[i][j] << " ";
		}
		// cout << "\n";
	}	

	bool valid = true;

	int xDir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int yDir[] = {-1, 0, 1, -1, 1, -1, 0, 1};

	rep(i, n){
		rep(j, m){
			if(a[i][j] == '.'){
				rep(k, 8){
					if(i + xDir[k] >= 0 && i + xDir[k] < n && j + yDir[k] >=0 && j + yDir[k] < m){
						if(a[i + xDir[k]][j + yDir[k]] == '*'){
							valid = false;
							cout << "NO";
							return 0;
						}
					}
				}
			}
			else if(a[i][j] >= '1' && a[i][j] <= '8'){
				int count = 0;
				rep(k, 8){
					if(i + xDir[k] >= 0 && i + xDir[k] < n && j + yDir[k] >=0 && j + yDir[k] < m){
						// cout << a[i + xDir[k]][j + yDir[k]] << "\n"; 
						if(a[i + xDir[k]][j + yDir[k]] == '*'){
							count ++ ;
						}
					}
				}
				int req = a[i][j] - 48;
				// cout << count << " " << req << "\n";
				if(count != req){
					valid = false;
					cout << "NO";
					return 0;
				}
			}
		}
	}

	cout << "YES";
	return 0;
}