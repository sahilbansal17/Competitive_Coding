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

bool sortDecMarksLexName(const pair <string, int> &a, const pair <string, int> &b){
	if(a.S == b.S){
		return a.F < b.F;
	}
	return a.S > b.S;
}

int main(){

	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int N;

	cin >> N;

	vector < pair <string, int> > classMarks;
	string name; 
	int marks;
	rep(i, N){
		cin >> name >> marks;
		classMarks.pb(mp(name, marks));
	}

	sort(classMarks.begin(), classMarks.end(), sortDecMarksLexName);

	rep(i, N){
		cout << classMarks[i].F << " " << classMarks[i].S << "\n";
	}	
	return 0;
}