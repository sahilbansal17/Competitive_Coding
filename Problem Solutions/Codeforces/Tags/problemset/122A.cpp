#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i < b; i ++)
#define RFOR(i,a,b) for(int i = a; i >= b; i --)
#define ln "\n"
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<"-->"<<y<<"\n"
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<"\n"

int lucky(int n){
	while(n != 0){
		int flag = 0;
		int x = n%10;
		n = n/10;
		if(x == 4 || x == 7)
			flag = 1;
		else 
			flag = 0;
		if(flag == 0){
			return 0;
		}
	}
	return 1;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int flag = 0;
	for(int i = 1; i < n; i ++){
		if(n%i == 0){
			//debug1(3);
			if(lucky(n/i)){
				flag = 1;
				break;
			}
		}
	}
	if(flag){
		cout<<"YES";
	}
	else{
		cout<<"NO";
	}
	return 0;
}