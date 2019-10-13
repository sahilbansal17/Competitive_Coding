/*Solution to a problem from Southern and Volga Russia Qualifier 2019-2020 in codeforces, using greedy*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

#define ri(a) scanf("%d", &a)
#define rii(a,b) scanf("%d %d", &a, &b)
#define riii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define rl(a) scanf("%lld", &a)
#define rll(a,b) scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int maxN = 2e5+4; // CAMBIAR ESTE

// GJNM
char s1[maxN], s2[maxN];
stack<int> change1, change2;
stack<pii> ans;

int main()
{
	int n; ri(n);
	scanf("%s %s", s1, s2);
	int ac, bc;
	ac = bc = 0;
	FOR(i,0,n)
	{
		if ( s1[i] == 'a') ac++;
		else bc++;
		if ( s2[i] == 'b') bc++;
		else ac++;
	}
	int swap = -1;
	if ( ac&1 || bc&1)
	{
		printf("-1\n");
		return 0;
	}
	FOR(i,0,n)
	{
		if ( s1[i] != s2[i] )
		{
			if ( s1[i] == 'a' ) change1.push( i );
			else change2.push( i );
		}
	}
	while ( change1.size() > 1)
	{
		int a,b;
		a = change1.top();
		change1.pop();
		b = change1.top();
		change1.pop();
		ans.push({a,b});
	}
	while ( change2.size() > 1)
	{
		int a,b;
		a = change2.top();
		change2.pop();
		b = change2.top();
		change2.pop();
		ans.push({a,b});
	}
	if ( change1.size() )
	{
		int a,b;
		a = change1.top();
		b = change2.top();
		ans.push({a,b});
		ans.push({a,a});
	}
	printf("%d\n",(int)ans.size() );
	while( !ans.empty() )
	{
		int a,b;
		a = ans.top().first;
		b = ans.top().second;
		ans.pop();
		printf("%d %d\n",a+1,b+1 );
	}	
	return 0;
}