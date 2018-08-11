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
	int total = 0;
	FOR(i,0,n){
		cin>>array[i];
	}
	FOR(i,0,n){
		total += array[i];
	}
	int hismoney = 0;
	int coins = n;
	sort(array, array+n);
	int i = 0;
	for(; hismoney <= total/2; coins--){
		hismoney += array[coins - 1];
		i++;
	}
	cout<<n - coins;
	return 0;
}