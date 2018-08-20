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
	int n, m;
	cin>>n>>m;
	int flag = 0;
	while(m >= 0){
		FOR(i,1,n+1){
			if(m-i >= 0){
				m -= i;
				//debug2(i,m);
			}
			else{
				//cout<<ln;
				//debug1(i);
				//cout<<ln;
				flag = 1;
				break;
			}
		}
		if(flag){
			break;
		}
	}
	cout<<m;
	return 0;
}