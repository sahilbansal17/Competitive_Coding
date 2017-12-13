#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <climits>
#include <iomanip>

using namespace std;

typedef vector <int> vi;
typedef pair <int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
#define FOR(i,a,b) for(int i(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define pb push_back
#define MOD 1000000007

vector <ll> solvedA(1000001,0);
vector <int> calculated(2000001,0);
int solved = 2;

int calc(int n){

	int even = 0,odd = 0;
	while(n!=0){
		int rem = n%10;
		if(n%2 == 0){
			even += rem;
		}
		else{
			odd += rem;
		}
		n/= 10;
	}
	return abs(even-odd);

}
ll solve(int n){

	if(n < solved){
		return solvedA[n];
	}
	else{
		FOR(j,solved+1,n+1){
			ll newsum = 0;
			calculated[j] = calculated[j-1];
			calculated[j] -= calc(j);
			calculated[j] += calc(2*j - 1);
			calculated[j] += calc(2*j - 2);
			newsum += calc(2*j);
			newsum += calculated[j]*2;
			solvedA[j] = newsum + solvedA[j-1];
		}
	}
	solved = n;
	return solvedA[n];
}



int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	solvedA[1] = 2; 
	solvedA[2] = 12;
	calculated[1] = 2;
	calculated[2] = 3;
	int t,n;
	cin >> t;
	FOR(i,0,t){
		cin >> n;
		cout << solve(n) << "\n";
	}

	return 0;
}
