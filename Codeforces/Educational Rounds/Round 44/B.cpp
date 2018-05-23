// original solution was hacked, modified after the contest
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

	int n, m;

	cin >> n >> m;

	char mat[2010][2010];

	vi count(m, 0); // no of switches connected to each lamp

	rep(i, n){
		rep(j, m){
			cin >> mat[i][j];
			if(mat[i][j] == '1'){
				count[j] ++ ;
			}
		}
	}

	bool res = 0;
	rep(i, n){
		// if there is a switch which is connected to lamps that are 
		// connected to more than one switches, then res = true
		bool currentSwitch = true;
		rep(j, m){
			if(mat[i][j] == '1' && count[j] == 1){
				currentSwitch = false;
			}
		}
		if(currentSwitch){
			res = true;
			break;
		}
	}
	if(res == 1){
		cout << "YES";
	}
	else{
		cout << "NO";
	}

	return 0;
}