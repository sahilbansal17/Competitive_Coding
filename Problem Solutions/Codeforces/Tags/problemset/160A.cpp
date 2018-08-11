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
	sort(array, array + n, greater<int>());
	int left = 0, right = 0;
	FOR(i, 0, n){
		left = 0, right = 0;
		FOR(k, 0, i+1){
			left += array[k];
		}
		FOR(j, i+1, n){
			right += array[j];
		}
		//debug2(left, right);
		if(left > right){
			cout<<(i+1)<<ln;
			break;
		}
	}
	return 0;
}