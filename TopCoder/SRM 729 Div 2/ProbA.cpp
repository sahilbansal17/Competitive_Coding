/* 	
 	author		: 	sahil_bansal1
	date		:	10th Feb, 2018	
*/
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
#define slen(s) s.length()
#define F first
#define S second

class BrokenChessboard{
public:
	int minimumFixes(vector <string> v){
		int ct1 = 0, ct2 = 0, len;
		rep(i,v.size()){
			len = slen(v[i]);
			rep(j,len){
				if((i + j)%2 == 0){
					if(v[i][j]!='B')
						ct1 ++;
					else
						ct2++;
				}
				else{
					if(v[i][j]!='W')
						ct1 ++;
					else
						ct2++;	
				}
			}
		}
		cout << min(ct1,ct2);
	}
};
