#include<bits/stdc++.h>

#define ll long long int
#define watch(x) cout << (#x) << " is " << (x) << endl  //watch function print variable and value for debugging
#define count_ones __builtin_popcountll                  // count_ones(9) is equal to 2 valid for ll also
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,n) for(ll i=0;i<n;i++)
using namespace std;
 
int main() {
 #ifndef ONLINE_JUDGE
	    freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
 #endif
       fast_io
 
       ll t;
       cin>>t;
       for(int i=0;i<t;i++)
       {
       	 ll n;
       	 cin>>n;
       	 	while(n%2==0)
       	 	{
       	 		n/=2;
       	 	}
       	 	cout<<"Case "<<(i+1)<<": "<<n<<"\n";
       }


   return 0;
 }