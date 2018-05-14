/* 	author		: 	sahilbansal17
	date		:	29th Jan, 2018	
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

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,m;

	cin >> n >> m;

	string ip,command,name;

	map< string, string > mp;
	map< string, string >::iterator it;
	rep(i,n){
		cin >> name >> ip;
		mp.insert(pair<string, string> (ip,name));
	}

	rep(i,m){
		cin >> command >> ip;
		cout << command << " " << ip << " ";
		ip.pop_back();
		it = mp.find(ip);
		cout << "#" << it->second << " ";
		cout << "\n";
	}

	return 0;
}