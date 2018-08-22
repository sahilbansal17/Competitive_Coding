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
	int max_joy = INT_MIN;
	cin>>n>>k;
	while(n--){
		int f,t;
		cin>>f>>t;
		int joy = 0;
		if(t > k)
			joy = f - (t - k);
		else
			joy = f;
		if(joy > max_joy)
			max_joy = joy;
	}
	cout<<max_joy;
	return 0;
}