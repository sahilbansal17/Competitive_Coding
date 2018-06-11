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

	int n;
	string s;
	cin >> n;

	vector <string> m(6, "");
	m[0] = "Power";
	m[1] = "Time";
	m[2] = "Space";
	m[3] = "Soul";
	m[4] = "Reality";
	m[5] = "Mind";

	bool visited[6] = {0};
	rep(i, n){
		cin >> s;
		if(s == "purple"){
			visited[0] = 1;
		}
		else if(s == "green"){
			visited[1] = 1;
		}
		else if(s == "blue"){
			visited[2] = 1;
		}
		else if(s == "orange"){
			visited[3] = 1;
		}
		else if(s == "red"){
			visited[4] = 1;
		}
		else if(s == "yellow"){
			visited[5] = 1;
		}
	}
	int count = 0;
	rep(i, 6){
		if(!visited[i]){
			count ++ ;
		}
	}
	cout << count << "\n";
	rep(i, 6){
		if(!visited[i]){
			cout << m[i] << "\n";
		}
	}
	return 0;
}