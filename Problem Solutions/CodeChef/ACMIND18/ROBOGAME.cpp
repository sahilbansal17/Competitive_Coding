#include<bits/stdc++.h>
using namespace std;
#define fl(i,a,n) for(int i=a;i<(n);++i)
#define rfl(i,a,n) for(int i=(n-1);i>a-1;i--)
#define rep(i,n) for(int i=1;i<=n;i++)
#define rrep(i,n) for(int i=n;i>0;i--)
#define srt(a,n) sort(a+1,a+n+1)
#define li long
#define ll long long
#define ull unsigned long long
#define clr(a) memset(a,0,sizeof(a))
#define vi vector <int>
#define vll vector <long long>
#define pii pair <int,int>
#define mod 1000000007
#define pb push_back
#define fr first
#define sc second
#define loop(i,n) for(int i=0;i<n;i++)
#define pi 3.1415926535
int countr[52];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>s;
		clr(countr);
		int n = s.length();
		//cout<<n<<endl;
		loop(i,n)
		{
			if(s[i]=='.') continue;
			else
			{
				int range = s[i] - '0';
				for(int j=i-range;j<=i+range;j++)
				{
					if(j<0||j>n) continue;
					countr[j]++;
				}
			}
		}
		bool possible = true;
		loop(i,n)
		{
			if(countr[i]>1)
			{
				possible = false;
				break;
			}
		}
		if(!possible)
		{
			cout<<"unsafe\n";
		}
		else cout<<"safe\n";
	}
	return 0;
}