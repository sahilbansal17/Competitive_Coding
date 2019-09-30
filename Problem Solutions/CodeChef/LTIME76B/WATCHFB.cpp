#include <bits/stdc++.h>
// Author: @NavonilDas
// Question: https://www.codechef.com/LTIME76B/problems/WATCHFB

using namespace std;
typedef long long i64;
typedef vector<int> vi;
typedef vector<i64> vi64;
typedef vector<vi> vvi;
typedef long double Ld;

#define  FastIo     ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define pb push_back
#define forn(i,n) for(int i=0;i<(int)(n);++i)
#define for1(i,n) for(int i=1;i<(int)(n);++i)
#define ford(i,n) for(int i=(int)(n);i>=0;--i)
#define forr(i,a,b) for(int i=(int)(a);i<=(int)(b);++i)                
#define fore(i,v) for(auto i:v)

template <class T> void Swap(T &a,T &b){T c=a;a=b;b=c;}
using namespace std;

int main(){
	#ifdef OFFLINE_EXE
	freopen("input.txt","r",stdin);
	#endif
	int t;
	cin>>t;
	while(t--){
		int n,o;
		cin>>n;
        long a,b,p1=-1,p2=-1;
    	bool deduct = false;// it is a boolean to set if it is possible to deduct output
		forn(i,n){
    		cin>>o>>a>>b;
    		deduct = false;// Set Default to false
            // if option is 1 we already know the score
    		if(o == 1)
    			deduct = true,p1 = a,p2 = b;
    		else {
    		    // if both scores are equal we know our favourite team score
                if(a == b)
        			deduct = true,p1 = a,p2 = b;
                
                // Check if one of the score is less than the previous score of the team
        		if(a < p1 || b<p2)
        		    deduct = true,p1 = b,p2 = a;
        		if(a < p2 || b < p1)
        		    deduct = true,p1 = a,p2 = b;
    		}
    		
    		if(deduct) cout<<"YES\n";
    		else cout<<"NO\n";
		}	
		
	}
	


	#ifdef OFFLINE_EXE
	cout<<"Time :"<<(1.0*clock()/CLOCKS_PER_SEC)<<"S.\n";
	#endif
	return 0;
}