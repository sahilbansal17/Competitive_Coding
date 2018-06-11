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

	int rows;

	cin >> rows;

	vector < pii > width(rows);

	rep(i, rows){
		cin >> width[i].F;
		width[i].S = i + 1;
	}

	srt(width);

	// rep(i, rows){
	// 	cout << width[i].F << " " << width[i].S << "\n";
	// }

	string passenger;
	cin >> passenger;

	vi res; 
	int counter = 0;
	stack <int> introverts;
	rep(i, 2*rows){
		if(passenger[i] == '0'){
			res.pb(width[counter].S);
			introverts.push(res[i]);
			counter ++;
		}
		else{
			res.pb(introverts.top());
			introverts.pop();
		}
	}

	rep(i, 2*rows){
		cout << res[i] << " ";
	}
	
	return 0;
}