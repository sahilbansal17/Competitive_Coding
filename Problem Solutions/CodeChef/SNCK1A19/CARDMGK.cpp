#include <bits/stdc++.h>
using namespace std;
#define fl(i,a,n) for(int i=a;i<(n);++i)
#define rfl(i,n) for(int i=(n);i>0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define srt(a) sort(a.begin(),a.end())
#define li long
#define lli long long
#define ull unsigned long long
#define clr(a) memset(a,0,sizeof(a))
#define vi vector <int>
#define vl vector <long>
#define pii pair <int,int>
#define mod 1000000007

int main() {

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		lli a[n];
		rep(i,n){
			cin>>a[i];
		}
		int ind=0;
		fl(i,1,n){
			if(a[i] < a[i-1])
				ind++;
		}
		
		if(ind == 0)
			cout<<"YES\n";
		else if(ind == 1 && a[n-1] <= a[0])
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	

	return 0;

}