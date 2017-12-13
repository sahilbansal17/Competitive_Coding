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

char mat1[100][100];

void init(){
	FOR(i,0,100){
		FOR(j,0,100){
			if((i+j) % 2 == 1){
				mat1[i][j] = 'R';
				//mat2[i][j] = 'G';
			}
			else{
				mat1[i][j] = 'G';
				//mat2[i][j] = 'R';
			}
		}
	}
}
ll solve(int n, int m){

	char a[n][m];
	int a1 = 0, a2 = 0;
	FOR(i,0,n){
		FOR(j,0,m){
			cin >> a[i][j];
			if(a[i][j] != mat1[i][j]){
				if(a[i][j] == 'R'){
					a1 += 5;
				}
				else
					a1 += 3;
			}
			else{
				if(a[i][j] == 'R'){
					a2 += 5;
				}
				else
					a2 += 3;	
			}
		}
	}
	return min(a1,a2);
}



int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int t,n,m;
	cin >> t;
	init();
	FOR(i,0,t){
		cin >> n >> m;
		cout << solve(n,m) << "\n";
	}

	return 0;
}
