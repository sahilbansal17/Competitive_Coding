#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int,int> pii;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)
#define F first
#define S second

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int T,n,m,left,top,mini;
	
	cin >> T;

	string a,b;

	while(T--){
		cin >> n >> m;
		cin >> a;
		cin >> b;

		pii dp[m+2][n+2],ptop,pleft;
		
		// first is the value of F(S) and second is for backtracking
		// second = 0 means last char from a
		// second = 1 means last char from b
		// second = 2 means either last char is from a or from b

		int ct = 1;
		dp[0][0].F = 0; dp[0][0].S = -1;
		dp[0][1].F = 1; dp[0][1].S = 0;
		dp[1][0].F = 1; dp[1][0].S = 1;
		// dp[i][j] is the min F(S) where S is merged string
		// containing 1st i char from B and 1st j char from A

		fl(i,2,n+1){
			if(a[i-1] != a[i-2])
				ct ++;
			dp[0][i].F = ct; 
			dp[0][i].S = 0;
		}

		ct = 1;
		fl(i,2,m+1){
			if(b[i-1] != b[i-2])
				ct ++;
			dp[i][0].F = ct;
			dp[i][0].S = 1;
		}

		fl(i,1,m+1){
			fl(j,1,n+1){
				pii top = dp[i-1][j];
				pii left = dp[i][j-1];

				mini = min(top.F,left.F);
			
				if(mini == top.F){
					if(top.S == 0){ // last char from a
						if(b[i-1] == a[j-1]){
							ptop.F = mini;
							ptop.S = 0; // no matter, still say a 
						}
						else{
							ptop.F = mini + 1;
							if(dp[i-1][j-1].F == top.F || ((i-2 >= 0) && dp[i-2][j].F == top.F))
								ptop.S = 1; // end in b
							else
								ptop.S = 2; // both exist
						}
					}
					else if(top.S == 1){ // last char from b
						if(i - 2 >= 0 && b[i-1] == b[i-2]){
							ptop.F = mini;
							ptop.S = 1; // end in b
						}
						else{
							ptop.F = mini + 1;
							ptop.S = 1; 
						}
					} 
					else{ // last char from either a or b
						// first check for a
						if(b[i-1] == a[j-1]){
							ptop.F = mini;
							ptop.S = 0; // no matter, still say a 	
						}
						else if(i - 2 >= 0 && b[i-1] == b[i-2]){
							ptop.F = mini;
							ptop.S = 1; // end in b
						}
						else{
							ptop.F = mini + 1;
							ptop.S = 1;
						}
					}
				}
				if(mini == left.F){
					if(left.S == 1){ // last char from b
						if(a[j-1] == b[i-1]){
							pleft.F = mini;
							pleft.S = 1; // no matter, still say b 
						}
						else{
							pleft.F = mini + 1;
							if(dp[i-1][j-1].F == left.F || ((j-2 >= 0) && dp[i][j-2].F == left.F))
								pleft.S = 0; // end in a
							else
								pleft.S = 2; // both exist
						}
					}
					else if(left.S == 0){ // last char from a
						if(j - 2 >= 0 && a[j-1] == a[j-2]){
							pleft.F = mini;
							pleft.S = 0; // end in a
						}
						else{
							pleft.F = mini + 1;
							pleft.S = 0;
						}
					} 
					else{ // last char from either a or b
						// first check for b
						if(b[i-1] == a[j-1]){
							pleft.F = mini;
							pleft.S = 1; // no matter, still say b	
						}
						else if(j - 2 >= 0 && a[j-1] == a[j-2]){
							pleft.F = mini;
							pleft.S = 0; // end in a
						}
						else{
							pleft.F = mini + 1;
							pleft.S = 0; 
						}
					}	
				}
				if(mini != top.F){
					dp[i][j] = pleft;
				}
				else if(mini != left.F){
					dp[i][j] = ptop;
				}
				else{
					if(ptop.F < pleft.F){
						dp[i][j] = ptop;
					}
					else if(ptop.F > pleft.F){
						dp[i][j] = pleft;
					}
					else{
						dp[i][j].F = pleft.F; // either of them
						if(ptop.S == 2 || pleft.S == 2){
							dp[i][j].S = 2;
						}
						else if(ptop.S == pleft.S){
							dp[i][j].S = ptop.S;
						}
						else{
							dp[i][j].S = 2;
						}
					}
				}
			}
		}
		 
		/*	FOR DEBUGGING 
			rep(i,m+1){
				rep(j,n+1){
					printf("%2d ",dp[i][j].F);
				}
				cout << "\n";
			}
			rep(i,m+1){
				rep(j,n+1){
					printf("%2d ",dp[i][j].S);
				}
				cout << "\n";
			}
		*/
			
		cout << dp[m][n].F << "\n";
	}
	
	return 0;
}