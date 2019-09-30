#include <bits/stdc++.h>
// Author: @NavonilDas
// Question: https://www.codechef.com/LTIME76B/problems/ALLSUB

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

// This function returns true if string s is a subset of string r
bool conatins(vi &a,vi &b){
	bool ret = true;
	forn(i,a.size()){
		a[i] -= b[i];
		if(a[i] < 0) {
			ret = false;
		}
	}	
	return ret;
}

int main(){
	#ifdef OFFLINE_EXE
	freopen("input.txt","r",stdin);
	#endif
	FastIo
	int t;
	cin>>t;
	while(t--){
		string s,r;
		cin>>s>>r;
		// vector conatining frequency of the charecters in string s r respectively
		vi hsh1(26,0),hsh2(26,0);
		short descending=0; // check if second charecter after the first charecter of s is smaller than or greater than it
		fore(c,s) {
			++hsh1[c-'a'];
			if(descending == 0 && c > s[0]) descending = 1;
			if(descending == 0 && c < s[0]) descending = 2;
		}
		fore(c,r) ++hsh2[c-'a'];

		if(conatins(hsh2,hsh1)){
			string sr = "";
			char fst = s[0]; // first charecter of string s

			// Append all the charecters which are smaller than the first charecter of s
			forn(i,fst-'a')
				while(hsh2[i]--)
					sr.pb('a'+i);
			
			// if the string s contains charecter which is smaller than first charecter then append the string s
			// then further append repetion of first charecter
			// example if s="babd" r = "bbbabaad" -> aa + babd + bb
			if(descending == 2) {
				sr += s;
				s.clear(); // Clear s as it is already appended
			}
			// append repetion of first charecter
			while(hsh2[fst-'a']--)
				sr.pb(fst);
			// if the string s contains charecter which is greater than first charecter then append the repetion of	
			// first charecter and then append the string s
			// example if s="bdba" r = "bbbabaad" -> aa + bb + bdba
			sr += s;
			// Append all the Remaing charecters
			forn(i,26)
				while(hsh2[i]-- > 0)
					sr.pb('a'+i);

			cout<<sr<<"\n";

		}else cout<<"Impossible\n";
	}

	#ifdef OFFLINE_EXE
	cout<<"Time :"<<(1.0*clock()/CLOCKS_PER_SEC)<<"S.\n";
	#endif
	return 0;
}