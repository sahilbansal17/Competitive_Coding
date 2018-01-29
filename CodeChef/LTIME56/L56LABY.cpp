/* 	author		: 	sahilbansal17
	date		:	27th Jan, 2018
	Works for Sub-Task 1
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair <int,int> pii;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rfl(i,a,b) for(int i(a);i>=(b);i--)
#define srt(v) sort((v).begin(),(v).end())
#define pb push_back
#define mp make_pair
#define F first
#define S second

int laby[1005][1005];
int res[1005][1005];
int vis[1005][1005];
int calls = 0;
void setLaby(int i, int j, int count, int n, int m){
	calls ++;
	if(laby[i][j] == -1){
		return ;
	}
	if(i < 1 || j < 1 || i > n || j > m){
		return;
	}
	if(res[i][j] > count){
		return;
	}
	if(res[i][j] == count && !vis[i][j]){
		vis[i][j] = 1;
	}
	else if(res[i][j] == count && vis[i][j]){
		return ;
	}
	if(count >= 0){
		res[i][j] = count;
	}
	if(count == 0){
		return ;
	}
	setLaby(i-1, j, count-1, n, m); //up
	setLaby(i, j-1, count-1, n, m); //left
	setLaby(i, j+1, count-1, n, m); //right
	setLaby(i+1, j, count-1, n, m); //down
}
int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int T,n,m;
	cin >> T;

	while(T--){
		cin >> n >> m;
		fl(i,1,n+1){
			fl(j,1,m+1){
				res[i][j] = -2;
				vis[i][j] = 0;
			}
		}
		vector < pair<int, pii> > exitCells;
		// indexing from 1
		fl(i,1,n+1){
			fl(j,1,m+1){
				cin >> laby[i][j];
				if(laby[i][j] > 0){
					exitCells.pb(mp(laby[i][j],mp(i,j)));
					res[i][j] = laby[i][j];
				}
				else if(laby[i][j] < 0){
					res[i][j] = -1; //blocked
				}
			}
		}
		srt(exitCells);
		rfl(i,exitCells.size()-1,0){
			// cout << exitCells[i]. F << "\n";
			int a = exitCells[i].S.F;
			int b = exitCells[i].S.S;
			setLaby(a, b, exitCells[i].F, n, m);
		}
		fl(i,1,n+1){
			fl(j,1,m+1){
				if(res[i][j] == -1){
					cout << "B";
				}
				else if(res[i][j] == -2){
					cout << "N";
				}
				else
					cout << "Y";
				// printf("%5d",res[i][j]);
			}
			cout << "\n";
		}
		// cout << calls << "\n";
		exitCells.clear();
	}

	return 0;
}