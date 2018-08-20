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
	int array[n];
	FOR(i,0,n)
		cin>>array[i];
	int total = 0;
	FOR(i,0,n)
		total += array[i];
	int ways = 0;
	if(total %  2 == 0){
		FOR(i, 0, n){
			if(array[i] % 2 == 0)
				ways++;
		}
	}
	else{
		FOR(i, 0, n){
			if(array[i] % 2 != 0)
				ways++;
		}
	}
	cout<<ways;
	return 0;
}