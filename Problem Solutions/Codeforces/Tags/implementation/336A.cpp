#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define RFOR(i,a,b) for(int i = a; i >= b; i --)
#define ln "\n"
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<"-->"<<y<<"\n"
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<"\n"
#define ll long long 

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll int x, y;
	cin>>x>>y;
	int a = abs(x) + abs(y);
	if(x > 0){
		if(y > 0){
			cout<<0<<" "<<a<<" "<<a<<" "<<0;
		}
		else{
			cout<<0<<" "<<-a<<" "<<a<<" "<<0;
		}
	}
	else{
		if(y > 0){
			cout<<-a<<" "<<0<<" "<<0<<" "<<a;
		}
		else{
			cout<<-a<<" "<<0<<" "<<0<<" "<<-a;
		}
	}
	return 0;
}