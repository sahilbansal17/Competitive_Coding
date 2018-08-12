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
	int k, n, w;
	cin>>k>>n>>w;
	int cost = 0, i = 0;
	while(w--){
		i++;
		cost += i*k;
	}
	//debug1(cost);
	if(cost > n)
		cout<<(cost - n)<<ln;
	else
		cout<<0<<ln;
	return 0;
}