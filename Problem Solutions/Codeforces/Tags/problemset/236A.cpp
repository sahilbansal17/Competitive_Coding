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
	int n = s.size();
	int array[26] = {0};
	FOR(i,0,n){
		//cout<<s[i]<<" ";
		//cout<<(s[i]-'a')<<" "<<ln;
		array[s[i] - 'a']++;
	}
	int count = 0;
	FOR(i,0,26){
		//debug1(array[i]);
		if(array[i] != 0)
			count++;
	}
	if(count % 2 == 0)
		cout<<"CHAT WITH HER!"<<ln;
	else
		cout<<"IGNORE HIM!"<<ln;
	return 0;
}