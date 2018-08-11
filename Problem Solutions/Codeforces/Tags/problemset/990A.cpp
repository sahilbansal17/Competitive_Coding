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
	long long int n, m, a, b;
	cin>>n>>m>>a>>b;
	if(n%m == 0){
		cout<<"0"<<ln;
	}
	else{
		long long int left = 0, right = 0;
		left = n - ((n/m)*m);
		right = ((n/m + 1)*m) - n;
		//debug2(left, right);
		left *= b;
		right *= a;
		//debug2(left, right);
		if(left <= right)
			cout<<left<<ln;
		else
			cout<<right<<ln;
	}
	return 0;
}