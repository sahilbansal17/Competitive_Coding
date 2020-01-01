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
const int maxN = 2e5+5; // CAMBIAR ESTE

// GJNM
int arr[maxN];
int n;

int main()
{
	ri(n);
	FOR(i,0,n)
	{
		ri(arr[i]);
	}
	ll prevP = 0, prevN = 0, prevZ = 0;
	ll tP = 0, tN = 0, tZ = 0;
	FOR(i,0,n)
	{
		if ( arr[i] > 0 )
		{
			prevP++;
			tP += prevP;
			tN += prevN;
			tZ += prevZ;
		}
		else if ( arr[i] < 0 )
		{
			int aux = prevP;
			prevP = prevN;
			prevN = aux + 1;
			tP += prevP;
			tN += prevN;
			tZ += prevZ;
		}
		else
		{
			//printf("%d\n", arr[i]);
			prevZ = i + 1;
			prevP = prevN = 0;
			tZ += prevZ;
		}
	}
	printf("%lld %lld %lld \n", tN, tZ, tP);
	return 0;
}