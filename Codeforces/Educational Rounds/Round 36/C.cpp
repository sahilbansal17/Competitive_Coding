// This solution was hacked 

#include <bits/stdc++.h>

using namespace std;

typedef vector <int> vi;
typedef pair <int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define fl(i,a,b) for(int i(a);i<(b);i++)
#define rep(i,n) fl(i,0,n)
#define rfl(i,a,b) for(int i(a);i>=(b);i--)
#define srt(v) sort((v).begin(),(v).end())
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define F first
#define S second

int main(){

	
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	string a,b,res;
	cin >> a >> b;

	vi ht(256,0);
	if(b.length() > a.length()){
		srt(a);
		rfl(i,a.length()-1,0){
			cout << a[i];
		}
	}
	else{	
		int index = - 1;
		rep(i,a.length()){
			ht[a[i]] ++ ;
		}
		rep(i,b.length()){
			if(ht[b[i]] >= 1){
				res += b[i];
				ht[b[i]] -- ;
				// cout << res << " ";
			}
			else{
				char ch = b[i] - 1;
				while(ch >= '0'){
					if(ht[ch] >= 1){
						break;
					}
					ch --;
				}
				if(ht[ch] >= 1){
					res += (ch);
					ht[ch] --;
					index = i;
					break;
					// cout << res << " ";
				}
				else{
					ht[res[i-1]] ++ ;
					char ch = res[i-1];
					ch --;
					while(ch >= '0'){
						if(ht[ch] >= 1){
							break;
						}
						ch --;
					}
					res.pop_back();
					res += ch;
					ht[ch] -- ;
					index = i;
					break;
				}
			}
		}
		if(index != -1){
			string temp;
			rep(i,256){
				if(ht[i]!=0){
					while(ht[i]--){
						temp += i;
					}
				}
			}
			srt(temp);
			// cout << temp << "\n";
			rfl(i,temp.length()-1,0){
				res += temp[i];
			}
		}
		cout << res;
	}
	return 0;
}