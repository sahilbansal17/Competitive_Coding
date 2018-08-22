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
	int left = 1, right = n*n;
	FOR(i,0,n){
		for(int j = 1; j <= n/2; j ++){
			cout<<left<<" "<<right<<" ";
			left++;
			right--;
		}
		cout<<ln;
	}
	return 0;
}