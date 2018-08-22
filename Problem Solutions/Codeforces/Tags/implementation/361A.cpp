#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define RFOR(i,a,b) for(int i = a; i >= b; i --)
#define ln "\n"
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<"-->"<<y<<"\n"
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<"\n"

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin>>n>>k;
	FOR(i,0,n){
		FOR(j,0,n){
			if(i == j){
				cout<<k;
			}
			else{
				cout<<0;
			}
			cout<<" ";
		}
		cout<<ln;
	}
	return 0;
}