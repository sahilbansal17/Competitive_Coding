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
	int array[n][3];
	FOR(i,0,n){
		FOR(j,0,3){
			cin>>array[i][j];
		}
	}
	int X = 0, Y = 0, Z = 0;
	FOR(i,0,n){
		X += array[i][0];
		Y += array[i][1];
		Z += array[i][2];
	}
	//debug3(X,Y,Z);
	if(X == 0 && Y == 0 && Z == 0)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}