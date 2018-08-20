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
	int n;
	cin>>n;
	n -= 10;
	if(n >= 2 && n <= 9){
		cout<<4;
	}
	else if(n == 10){
		cout<<15;
	}
	else if(n == 1 || n == 11){
		cout<<4;
	}
	else
		cout<<0;
	return 0;
}