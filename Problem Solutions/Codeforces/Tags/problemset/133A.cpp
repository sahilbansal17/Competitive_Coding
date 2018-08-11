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
	string s;
	cin>>s;
	int flag = 0;
	FOR(i,0,s.size()){
		if(s[i] == 'H' || s[i] == 'Q' || s[i] == '9'){
			cout<<"YES";
			flag = 1;
			break;
		}
		else{
			;
		}
	}
	if(!flag)
		cout<<"NO";
	return 0;
}