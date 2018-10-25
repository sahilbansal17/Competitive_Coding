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

int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b, a%b);
}
int s = 0;
int visited[55];
bool dfs(int a[], int n, int index){
	visited[index]=1;
	s++;
	if(s == n){
		return true;
	}
	rep(i,n){
		if(visited[i]==0 && gcd(a[i], a[index])==1)
			if(dfs(a,n,i)) return true;
	}
	return false;
}

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
		int b[n];
		rep(i,n){
			cin>>b[i];
			visited[i]=0;
		}
		s=0;
		bool flag = dfs(b,n,0);
		if(flag){
			cout<<0<<endl;
			rep(i,n){
				cout<<b[i]<<" ";
			}
			cout<<endl;
		}else{
			int c29=0,c31=0,c37=0,c41=0,c43=0,c47=0;
			rep(i,n){
				switch(b[i]){
					case 29: c29++;break;
					case 31: c31++;break;
					case 37: c37++;break;
					case 41: c41++;break;
					case 43: c43++;break;
					case 47: c47++;break;
				}
			}
			if(c29==0){
				b[0]=29;
			}else if(c31 == 0){
				b[0]=31;
			}else if(c37 == 0){
				b[0]=37;
			}else if(c41 == 0){
				b[0]=41;
			}else if(c43 == 0){
				b[0]=43;
			}else{
				b[0]=47;
			}
			cout<<1<<endl;
			rep(i,n){
				cout<<b[i]<<" ";
			}
			cout<<endl;
		}
	}	

	return 0;

}