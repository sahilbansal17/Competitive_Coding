#include<bits/stdc++.h>
#define lli long long int
#define vll vector<lli>
#define mp make_pair
#define ff first
#define ss second
#define BR cout<<endl
#define truent false
#define bug(bleh) cerr<<#bleh<<"="<<bleh<<endl
#define forbug(BL,EH) cerr<<endl;for(lli iii=0;iii<EH;iii++) cerr<<iii<<": "<<BL[iii]<<endl;
using namespace std;
const lli MOD = 1000000007,N=123456;
lli a[N];
inline lli read()	{
	lli x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
 
int main()	{
	lli n=read(),m=read(),k=-MOD,mx=0,mn=0,sum=0;
	memset(a,0,sizeof a);
	if(n==1)	{
		sum=read()+m;
		cout<<sum<<" "<<sum<<endl;
		return 0;
	}
	for(lli i=0;i<n;i++)	a[i]=read();
	for(lli i=0;i<n;i++)	{k=max(k,a[i]);sum+=a[i];}
	mx = k+m; 
	if((sum+m)<=n*k) mn=k;
	else mn = (sum+m)/n + (((sum+m)%n)?(1):(0));
	cout<<mn<<" "<<mx<<endl;
	return 0;
}