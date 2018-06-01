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
#define vpii vector< pii >

int main(){

	#ifndef ONLINE_JUDGE
	freopen("/Users/sahilbansal/Desktop/input.txt","r",stdin);
	freopen("/Users/sahilbansal/Desktop/output.txt","w",stdout);
	#endif

	int n, m, skill, x, y;

	cin >> n >> m;

	vpii skills;
	vi skills_unsorted; // to keep original ordering, used in last part

	rep(i, n){
		cin >> skill;
		skills.pb(mp(skill, i + 1));
		skills_unsorted.pb(skill);
	}

	vi quarrel[200010]; // for quarrel pairs

	rep(i, m){
		cin >> x >> y;
		quarrel[x].pb(y);
		quarrel[y].pb(x);
	}

	srt(skills);

	vi count(n + 1, 0); // max possible programmers for which i-th can be mentor

	// pre-compute for no quarrels, then subtract visiting each quarrel edge
	int max = n - 1, current; 
	while(max > 0){
		current = max;
		while(max >= 1 && skills[max - 1].F == skills[max].F){
			max --; // for same skilled programmers
		}
		if(max == current){
			count[skills[max].S] = max; // the index is 2nd element of pair
		}
		else{
			fl(i, max, current + 1){
				count[skills[i].S] = max;
			}
		}
		max --; // next programmer with less skills
	}
	/*
	fl(i, 1, n + 1){
		cout << count[i] << " " ;
	}
	*/
	// now consider all adjacency lists, if quarrel[i] has j and
	// also if skill of i > skill of j , then count[i] --

	fl(i, 1, n + 1){
		rep(j, quarrel[i].size()){
			int to = quarrel[i][j];
			if(skills_unsorted[i - 1] > skills_unsorted[to - 1]){
				count[i] -- ;
			}
		}
	}

	fl(i, 1, n + 1){
		cout << count[i] << " " ;
	}
	return 0;
}