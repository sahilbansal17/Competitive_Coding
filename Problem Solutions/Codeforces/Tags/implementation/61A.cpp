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
	string a, b;
	cin>>a>>b;
	//string c;
	char c[a.size()];
	FOR(i,0,a.size()){
		if((a[i] == '0' && b[i] == '1') || (a[i] == '1' && b[i] == '0')){
			c[i] = '1';
		}
		else{
			c[i] = '0';
		}
	}
	FOR(i,0,a.size()){
		cout<<c[i];
	}
	return 0;
}