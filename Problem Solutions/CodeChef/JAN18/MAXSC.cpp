#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef long long ll;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)
#define rfl(i,a,b) for(int i(a);i>=(b);i--)
#define srt(v) sort((v).begin(),(v).end())
int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t,n,x;
	cin >> t;

	vi a[705];
	while(t--){

		ll res = 0;
		int cmax;

		cin >> n;
		rep(i,n){
			rep(j,n){
				cin >> x;
				a[i].pb(x);
			}
		}

		rep(i,n){
			srt(a[i]);
		}

		/*
		rep(i,n){
			rep(j,n){
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		*/

		res = a[n-1][n-1];
		cmax = res;

		int out_flag = 0;
		rfl(i,n-2,0){
			int flag = 0;
			rfl(j,n-1,0){
				if(a[i][j] < cmax){
					flag = 1;
					cmax = a[i][j];
					res += cmax;
					break;
				}
			}
			if(flag == 0){
				out_flag = 1;
				break;
			}
		}

		if(out_flag == 0)
			cout << res << "\n";
		else
			cout << "-1\n";
		
		rep(i,n){
			a[i].clear();
		}
	}

	return 0;
}