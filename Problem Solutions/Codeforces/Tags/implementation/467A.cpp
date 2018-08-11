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
	int array[n][2];
	FOR(i,0,n){
		FOR(j,0,2)
			cin>>array[i][j];
	}
	int count = 0;
	FOR(i,0,n){
		if(array[i][1] - array[i][0] >= 2){
			count++;
		}
	}
	cout<<count<<ln;
	return 0;
}