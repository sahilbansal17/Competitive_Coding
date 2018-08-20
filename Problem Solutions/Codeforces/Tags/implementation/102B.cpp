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
	int count = 0;
	long long int sum;
	int n = s.size();
	while(n != 1)
	{
		sum = 0;
		FOR(i,0,n)
			sum += s[i] - '0';
		s = to_string(sum);
		n = s.size();
		//debug1(n);
		count++;
	}
	cout<<count;
	return 0;
}
