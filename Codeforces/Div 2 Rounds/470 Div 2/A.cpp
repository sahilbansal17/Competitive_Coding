/* 	
 	author		: 	sahilbansal17
	date		:	10th March, 2018	
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

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int r,c;

	cin >> r >> c;

	char s[505][505];

	rep(i, r){
		rep(j, c){
			cin >> s[i][j];
		}
	}	

	int flag = 0 ;

	rep(i, r){
		fl(j, 1, c){
			if((s[i][j] == 'S' && s[i][j-1] == 'W') || (s[i][j] == 'W' && s[i][j-1] == 'S')){
				flag = 1;
				break;
			}
		}
	}

	rep(j, c){
		fl(i, 1, r){
			if((s[i][j] == 'S' && s[i-1][j] == 'W') || (s[i][j] == 'W' && s[i-1][j] == 'S')){
				flag = 1;
				break;
			}
		}
	}

	if(flag == 1){
		cout << "No";
	}
	else{
		cout << "Yes\n";
		rep(i, r){
			rep(j, c){
				if(s[i][j] == '.'){
					cout << "D";
				}
				else{
					cout << s[i][j];
				}
			}
			cout << "\n";
		}
	}



	return 0;
}