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
	int n,t;
	cin>>n>>t;
	string s;
	cin>>s;
	while(t--)
	{
		for(int i = 0; i < n; i ++)
		{
			if(s[i] == 'B' && s[i+1] == 'G')
			{
				swap(s[i], s[i+1]);
				i++;
			}
			else
			{
				;
			}
		}
	}
	cout<<s;
	return 0;
}